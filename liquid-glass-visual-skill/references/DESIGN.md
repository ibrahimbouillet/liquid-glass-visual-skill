# Visual contract

**Goal:** a thin, responsive glass layer above real content. Opacity + blur alone does not pass. Use the host project's renderer; this file defines *results*, not code.

## 1. Layout and hierarchy

- Use glass mainly for floating navigation, toolbars, controls, menus, search, and transient chrome. Do not coat articles, lists, data tables, or every panel.
- Give each control a meaningful shape, radius and spacing. A pill works for compact actions; larger menus need different geometry.
- Show depth with soft shadow and a fine outline. Avoid gray slabs, thick white strokes, hard shadows, neon glow, and glass stacked on glass.
- Active elements inside glass use a simple tint/highlight, **not** another backdrop sample.

## 2. Optical cues

1. **Transmission:** backdrop colors and broad shapes remain visible.
2. **Diffusion:** detailed areas behind labels soften enough to read; adjust by backdrop complexity.
3. **Edge lensing:** slight optical bend or brightness concentration near curved edges, not under text.
4. **Specular rim:** thin directional highlights respond to shape and state; no persistent neon stroke.
5. **Depth:** shallow ambient shadow grows on busy backgrounds and recedes on calm ones.
6. **Clean masks:** no rectangular blur leaks, edge seams, color fringing, banding, or sampling artifacts.

Keep the center calm and the edge lively. Subtlety beats a showcase effect.

## 3. Adaptive material

- **Regular (default):** translucent, responsive blur/luminance and foreground contrast. Use for navigation, menus, labels and uncertain backdrops.
- **Clear (rare):** much more transparent, with less automatic adaptation. Use over rich media only when tested dimming protects bold, bright foreground text.
- Adapt to **the visible composited backdrop under each glass region**, not merely the app's light/dark theme or screen-wide average.
- Text and icons stay legible over white, black, saturated, detailed, split-tone and moving areas.
- A small control may switch dark/light foreground. Add a stable threshold and time hysteresis so color never chatters near a threshold.
- Large menus should keep a stable overall tone rather than flash between whole-panel modes.
- When text scrolls beneath a floating bar, it must not visually merge with bar labels. Strengthen local separation without hiding the page.

## 4. Motion and input

- Hover, press, release, drag, focus and selection produce near-immediate, smooth, reversible responses.
- Moving or merging controls preserve spatial continuity, sensible hit targets and legible glyphs.
- Rim light may follow input direction. Keep idle motion near zero.
- Avoid infinite shimmer, gratuitous bounce, hard alpha swaps, blurred letters and dramatic overshoot.
- Tune motion for the actual platform and rendering budget, not a universal timing preset.

## 5. Accessibility

- Check **final composited pixels**, including difficult image areas and disabled/focused states.
- Relevant WCAG 2.2 AA targets: normal text contrast >= **4.5:1**; large text >= **3:1**; essential non-text visual states >= **3:1**. Apply the actual WCAG definitions and exceptions.
- Preserve focus visibility, hit targets, zoom, keyboard access and accessible names where supported.
- Honor reduced motion, reduced transparency and increased contrast. Use a stable opaque or high-contrast surface if needed.
- Never let glass rendering block core app actions or make text impossible to read.

## 6. Performance and fallback

- Measure on target hardware during scrolling, video backgrounds, animation and resize.
- Avoid sync frame reads, repeated full-screen captures, oversized blur, CPU work on the UI thread and redundant layers.
- Prefer native composition where the SDK supports it; else use bounded GPU processing; else a safe opaque/semi-opaque fallback.
- Check multi-monitor scale, color space, alpha blending, device-loss and memory pressure as relevant.

## Failure examples

Unreadable labels; rapid black/white text flips; a white blurred slab; fake edge glow; nested glass; sampling outside the shape; clipped refraction; delayed click response; inaccessible controls; performance regressions.

For comparison workflow and image references, see [IMAGES.md](IMAGES.md) and [TESTS.md](TESTS.md). Images in `assets/` are **original test illustrations**, not Apple screenshots.
