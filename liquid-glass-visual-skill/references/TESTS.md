# Acceptance tests

Run tests on a **real rendered build**. Code review or still mockups alone cannot verify adaptation or motion.

| ID | Scene | Required evidence |
| --- | --- | --- |
| G01 | White / very light backdrop | Visible boundary; readable glyphs |
| G02 | Black / near-black backdrop | Readable glyphs; no hard glow |
| G03 | Split black-white behind one control | Local protection on both sides |
| G04 | Detailed photo, mixed tones | Backdrop sensed; labels still clear |
| G05 | Saturated colors and gradients | Color transmits; contrast stays usable |
| G06 | Text scrolling under floating toolbar | Text from different layers never merges |
| G07 | Moving/video background | No contrast oscillation or edge flicker |
| G08 | Hover/press/hold/release | Prompt, smooth, reversible response |
| G09 | Keyboard focus and accessibility API | Visible focus, intact interaction |
| G10 | Menu from glass control | Spatial continuity, correct depth and z-order |
| G11 | Multiple nearby controls | No unneeded double blur/glass stack |
| G12 | Resize, DPI and zoom | Sharp masks, stable hit regions |
| G13 | Reduced motion | No essential interaction lost; motion reduced |
| G14 | Reduced transparency / high contrast | Readable fallback |
| G15 | Theme / mode switch | Correct appearance; other themes unaffected |
| G16 | Stress: busy scene + scroll + anim | No severe stalls, lag or artifacts |
| G17 | No compositor/shader path | Safe functional fallback |
| G18 | Offline / restricted permissions | No networking or credentials required |

## Image-based review

1. Follow [IMAGES.md](IMAGES.md): view **Apple's official images/videos** separately from the repository's original test scenes.
2. Render identical UI states over light, dark and mixed backgrounds, including a 2x crop of rim, text and shadow.
3. Compare transmission, blur, edge lensing, rim highlight, depth, stable contrast and spacing. Do **not** score only resemblance to a single frame.
4. Record a short interaction + scroll + moving-backdrop clip: static shots cannot prove fluid motion.
5. Check contrast from final composed pixels at text edges and across difficult backgrounds (WCAG guidance where applicable).
6. Report frame times/input latency and hardware where measurable. Note any platform-specific limits.

## Report template

For each applicable test, report **PASS / FAIL / NOT_TESTED / N/A**, platform and version, evidence file/link, measured or observed result, and fixes needed.

**Release gate:** G01–G08 and applicable accessibility/scope tests must pass. Never silently convert NOT_TESTED to PASS, and never call a result pixel-perfect Apple Liquid Glass without verifiable proof.
