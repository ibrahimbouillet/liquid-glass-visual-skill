# C++ guide (optional)

Load **only for C++ tasks**. Inspect the host app and preserve its architecture. This is a decision guide, not mandatory sample code or a fixed dependency list.

## Pick the renderer path

| Existing stack | Examine first |
| --- | --- |
| Objective-C++ / macOS native | Available AppKit/SwiftUI/UIKit glass APIs for the target SDK/OS; no assumption of public C++ glass API |
| Qt Quick | Scene graph, ShaderEffect, texture capture, Qt version / renderer constraints |
| Qt Widgets | Existing paint/compositor support; avoid synchronous screen grabs |
| JUCE, SDL, SFML, wxWidgets | Who owns UI composition, framebuffer, typography and hit testing |
| Dear ImGui | Backend and draw order; ensure backdrop exists before sampling |
| OpenGL / Vulkan / Metal / Direct3D / Skia | Existing render graph, framebuffers, masks, alpha and color space |
| Windows compositor | Native backdrop materials as possible substitutes, **not** Apple Liquid Glass |
| Weak/unknown path | First ship an accessible, low-cost fallback |

Docs: [Qt](https://doc.qt.io/), [JUCE](https://juce.com/learn/documentation), [Skia](https://skia.org/docs/), [SDL](https://wiki.libsdl.org/), [Vulkan](https://docs.vulkan.org/), [OpenGL](https://registry.khronos.org/OpenGL/), [Metal](https://developer.apple.com/metal/), [DirectComposition](https://learn.microsoft.com/windows/win32/directcomp/directcomposition-portal), [Dear ImGui](https://github.com/ocornut/imgui).

## Possible GPU stages (choose only those needed)

1. Sample an **already-rendered valid backdrop texture** behind the glass region. Never sample the current glass recursively.
2. Blur only within bounds; use downsample/separable methods if they help. Maintain correct alpha and rounded masks.
3. Tune luminance/tint and diffusion to local detail for **Regular** glass.
4. Add **small edge-only** lens distortion; clamp sampling and do not bend text.
5. Add a thin specular rim and soft ambient shadow. Render labels separately, sharp.
6. Choose text/icon polarity from the effective composed background, not one pixel. Smooth decisions over time; never flip every frame.
7. Animate with the app's render clock, without blocking input or GPU with a synchronous readback.
8. Switch to a safe, higher-contrast fallback for reduced transparency, weak hardware or unavailable sampling.

Native compositor APIs may do much of this automatically. **Prefer existing project tools over added dependencies.**

## C++ helper

`../tools/contrast.hpp` provides tiny **pure math** helpers for sRGB luminance and contrast. It does **not** sample pixels, render glass, or guarantee WCAG compliance. Use it only for individual known opaque colors; the calling app must obtain the correct final backdrop samples.

## Common pitfalls

- Sampling the whole screen for every frame; GPU-to-CPU readbacks on the UI thread.
- Mixing premultiplied and straight alpha, or blurring in the wrong color space.
- Hardcoded DPI, radius, text polarity or one backdrop value for large surfaces.
- Double-filtering nested controls, overly large Gaussian kernels, self-feedback loops.
- Shader code from untrusted sites or copied Apple binaries/private APIs.
- Claiming benchmark results without compiling and testing the actual application.
