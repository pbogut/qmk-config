# My mostly Colemak layout with some Vim flavour

Main conception was to have Colemak layout with some Vim feeling outside the Vim.
I've tried to avoid putting keys in the place where modifiers are.

## Layers

### L0 - Normal

It's Colemak layout with minor changes. Backspace is replaced with `Ctrl / ESC`
macro, backspace itself can be produced by `LCtrl + H`.

### L1 - Programming layer

Symbols usually produced by Shift + [0-9] and some extra on left halve. Numbers
and keys usually placed on numeric pad on the right one. Note that those are
normal numbers, not numpad ones.

### L2 - Navigation layer

Mouse, arrows and scrolls. They are in place where those actions are in Vim.
So arrows are on HKJL, scrolls Y/E, D/F etc. (I'm fun of native Vim keys even
when using Colemak layout).

### L3 - Media / Numpad Layer

It's mostly 'I barely use it and I have no idea where else to place it' layer.

## Macros

### LCtrl / Esc

Left `Ctrl` works as ESC when tap. I had to create separate macro for that as
I wanted to combine it with the next macro (`LCtrl` + `H`).

### LCtrl + H as a backspace

I never liked backspace key placement on normal keyboard and I get used to use
`<C-H>` in Vim. So with this layout if you press left `Ctrl`
(placed where normally caps lock is) and `H` it will send backspace.
You can still access normal `Ctrl` + `H` behaviour by using right `Ctrl`.

### RCtrl + D as a del

That just felt right after creating previous macro.
You can still access normal `Ctrl` + D behaviour by using left `Ctrl`.

### Space Cadet Shift - ish

I love the Space Cadet Shift idea, where your shifts are producing `(` and `)`,
but I didn't like the build in behaviour. With my implementation parentheses
are inserted only on short tap, if you hold your shift for too long it does
nothing.

### Tab / L1

Tab works as a tab when tap and layer switch when pressed. Even though there is
build in implementation in QMK for that purpose it works with tiny lag. So if
you press layer switch and key too fast it's not switching the layer...  a bit
annoying. My macro works straight away. Downside of it is when you press
something before tab is fully released, you will end up with key from the
L1 layer. Personally less annoying for me, and happens less frequent.

### Backslash / L1

Similar to the one above.

### `->` `<-` `=>` `|>`

I've found useful to have those on one key.



