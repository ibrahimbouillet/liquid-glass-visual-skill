---
name: liquid-glass-visual-skill
description: Builds and audits adaptive, Apple-inspired Liquid Glass interfaces across UI stacks, including C++. Use for glassmorphism, translucent controls, backdrop blur, dynamic contrast, refraction, fluid motion, accessibility, or visual regression tests.
---

# Liquid Glass: adaptive UI skill

## Goal
Deliver **working, high-fidelity glass UI**, not a static mockup. Use the host project's real code, renderer and constraints. Match Apple's *design principles*, not undocumented private internals. Never promise pixel-perfect parity.

## Read once, then load as needed
- **Always** read [DESIGN.md](references/DESIGN.md) for perceptual targets.
- **Always before editing** read [SECURITY.md](references/SECURITY.md).
- **For C++ only** read [CPP.md](references/CPP.md); optional `tools/contrast.hpp`.
- **When implementing or reviewing** read [TESTS.md](references/TESTS.md).
- **For visual comparison** read [IMAGES.md](references/IMAGES.md); inspect actual Apple web demos when browser access is available.
- **To verify claims** read [SOURCES.md](references/SOURCES.md).

## Required outcome
1. **Correct layer:** glass belongs mainly to navigation, floating controls and transient chrome. Keep content clear; avoid glass-on-glass.
2. **Optics:** a translucent backdrop with controlled local diffusion, edge lensing, fine highlights, soft depth and stable contours. Neither flat opacity nor a uniform white blur qualifies.
3. **Adaptation:** sample or infer the **actual backdrop under each surface**. Regular glass adjusts to changing light/dark/detail; text and symbols retain contrast without rapid color toggles. Clear glass is optional and needs verified dimming/readability.
4. **Motion:** immediate feedback, coherent shape/position transitions, stable idle state, responsive scroll and no flicker or obvious frame stalls.
5. **Access:** usable focus, hit targets, reduced motion/transparency and high-contrast fallback; validate rendered contrast.
6. **Scope:** retain existing features, app layout intent, input behavior, and all unrelated themes.

## Workflow
1. Inspect repo, UI stack, target OS, rendering path, frame budget, and user-specified scope. **Do not assume** variables, framework, libraries or file paths.
2. Identify glass candidates; explain which content **must remain non-glass**.
3. Pick native composition where available, else an efficient custom pass, else a readable fallback. Reuse existing project tools.
4. Implement in small, reviewable changes. Do not fetch/run untrusted code or change build/dependency settings without justification and approval.
5. Inspect official visual examples linked in [IMAGES.md](references/IMAGES.md), if browsing is available. Compare the **real rendered UI** against the perceptual criteria; use [TESTS.md](references/TESTS.md). Fix failures before marking done.
6. Report changed files, visual evidence, tests `PASS/FAIL/NOT_TESTED`, limits and performance trade-offs. If live rendering is unavailable, **say so**; do not invent results.

## Stop conditions
**FAIL** if text disappears on a moving/mixed backdrop; contrast flickers; glass stacks repeatedly; interaction or accessibility breaks; the feature becomes too slow; or results are presented as tested without evidence.

Keep responses concise. Read optional details only for the current stack and task.
