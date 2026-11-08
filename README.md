# Universal Liquid Glass Visual Skill

A **public, reusable AI skill** for designing and validating interfaces inspired by Apple's Liquid Glass visual language. **Not tied to any application, repository, programming language, or UI toolkit.**

It helps AI coding agents (including Claude Code) inspect an existing project, choose appropriate capabilities, and reproduce observable *glass-like* behavior while preserving readability, motion accessibility, performance, and existing functionality.

> Independent community project. Not affiliated with, endorsed by, or a replacement for Apple's proprietary Liquid Glass implementation. Pixel-perfect parity cannot be guaranteed across different engines and platforms.

## Install / Use

For Claude or a skill-aware coding agent, point it to:

`liquid-glass-visual-skill/SKILL.md`

Read all linked references before implementing. Or copy the entire `liquid-glass-visual-skill` folder into the agent's skills directory, following the agent's own documentation.

**Generic prompt:**

> Use the `liquid-glass-visual-skill` skill from this repository to implement or improve Liquid Glass styling in my project. Inspect the actual codebase, platform, UI toolkit, graphics capabilities, and performance constraints first. Follow the observable design and acceptance criteria. Select techniques appropriate to my project instead of assuming an architecture. If the project uses C++, consult `references/CPP_GUIDE.md`. Preserve existing behavior, validate legibility on changing backgrounds, and report evidence and limitations.

## Contents

- [SKILL.md](liquid-glass-visual-skill/SKILL.md): activation, observable acceptance contract, AI workflow.
- [Visual charter](liquid-glass-visual-skill/references/CHARTE_VISUELLE.md): perceptual and functional appearance criteria.
- [Validation matrix](liquid-glass-visual-skill/references/VALIDATION_VISUELLE.md): test scenes and evidence checklist.
- [C++ guide](liquid-glass-visual-skill/references/CPP_GUIDE.md): optional decision tree and techniques for C++ UI/graphics stacks.
- [Sources](liquid-glass-visual-skill/references/SOURCES.md): primary Apple and accessibility references, limitations.

## Principles

- Glass mainly for controls, navigation, and top-layer UI, **not** every content surface.
- **Regular** adaptive glass by default; **Clear** only where legibility can be secured.
- Dynamic local contrast without flicker or sudden oscillation.
- Subtle boundary highlights, dimensionality, context-aware obscuration and motion.
- No unnecessary multiple layers of glass; no overdone glow.
- Respect reduced transparency, reduced motion, and increased contrast settings.
- Verify realistic backgrounds and motion, not only a static screenshot.

## License

MIT. See [LICENSE](LICENSE). Apple trademarks and artwork remain the property of their respective owners. No Apple assets or proprietary implementations are bundled.
