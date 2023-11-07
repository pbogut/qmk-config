#!/usr/bin/env bash
#=================================================
# name:   helper
# author: author <author_contact>
# date:   06/11/2023
#=================================================
dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$dir" || exit 1

action=""
half="both"
kb=""

usage() {
    echo "Ussage: ${0##*/} <ACTION> [OPTIONS]"
    echo ""
    echo "Action:"
    echo "  init                   initlaize"
    echo "  deps                   install dependencies"
    echo "  compile [keyboard]     build firmware [half: both,left,right] default: both"
    echo "  flash [keyboard]       build firmware [half: left,right]"
    echo "  cleanup                cleanup"
    echo ""
    echo "Options:"
    echo "  --left                 perform action for left half"
    echo "  --right                perform action for right half"
    echo "  -h, --help             display this help and exit"
}

while test $# -gt 0; do
    case "$1" in
        --left)
            half="left"
            shift
            ;;
        --right)
            half="right"
            shift
            ;;
        deps)
            action="deps"
            shift
            ;;
        init)
            action="init"
            shift
            ;;
        flash)
            action="flash"
            shift
            kb="$1"
            shift
            ;;
        compile)
            action="compile"
            shift
            kb="$1"
            shift
            ;;
        cleanup)
            action="cleanup"
            shift
            ;;
        --help | -h)
            usage
            exit 0
            ;;
        *)
            usage
            exit 1
            ;;
    esac
done

if [[ -z $action ]]; then
    usage
    exit 1
fi

if [[ $action == "deps" ]]; then
    paru -S qmk jq
fi

if [[ $action == "init" ]]; then
    qmk clone
fi

if [[ $action == "cleanup" ]]; then
    rm -fr qmk_firmware
fi

__link() {
    src=$(jq ".$kb.src" -r config.json)
    dst=$(jq ".$kb.dst" -r config.json)

    if [[ -z $src ]] || [[ -z $dst ]]; then
        exit 1
    fi
    rm "qmk_firmware/$dst"
    ln -sf "$dir/$src" "qmk_firmware/$dst"
}

if [[ $action == "compile" ]]; then
    __link
    build=$(jq ".$kb.build" -r config.json)
    cd "qmk_firmware" || exit 1
    # shellcheck disable=SC2086
    qmk compile $build
fi

if [[ $action == "flash" ]]; then
    __link
    build=$(jq ".$kb.build" -r config.json)

    if [[ $half == "left" ]]; then
        bootloader=$(jq ".$kb.left" -r config.json)
    elif [[ $half == "right" ]]; then
        bootloader=$(jq ".$kb.right" -r config.json)
    fi
    cd "qmk_firmware" || exit 1
    # shellcheck disable=SC2086
    if [[ "$bootloader" = "null" ]]; then
        qmk flash $build
    else
        qmk flash $build $bootloader
    fi
fi
