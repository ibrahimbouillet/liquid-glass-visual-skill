# Liquid Glass Visual Skill

**Skill public et indépendant pour Claude / Claude Code**, basé sur l'étude des principes Liquid Glass présentés publiquement par Apple. Il décrit des **résultats visuels observables** et des tests d'acceptation ; il **ne prescrit aucune technologie**, aucun framework et aucune architecture d'application.

Version initiale : 1.0.0 (8 novembre 2026). Langue : français.

## Contenu

```text
liquid-glass-visual-skill/
  SKILL.md
  references/
    CHARTE_VISUELLE.md
    VALIDATION_VISUELLE.md
    SOURCES.md
PROMPT_ATHERSHELL_ALPHA4.md
README.md
LICENSE
```

Ce dépôt est **séparé du code d'AtherShell**. L'application AtherShell n'est pas incluse et ne doit jamais être ajoutée à ce dépôt.

## Objectif

- Translucidité, relief, reflets fins, effets de bord et couche d'interaction flottante.
- Adaptation du contraste réel au fond, lisibilité des textes et des icônes.
- Défilement et menus fluides ; variations de taille et d'état cohérentes.
- Usage modéré du verre et rejet des surfaces vitrées superposées.
- Respect de la transparence réduite, du contraste augmenté et du mouvement réduit.
- Validation observable sur des scènes difficiles, sans revendication de copie exacte du moteur Apple.

## Installer dans Claude (interface web)

1. Télécharger l'archive `liquid-glass-visual-skill-claude.zip` fournie avec la distribution (ou fabriquer un ZIP contenant **le dossier** `liquid-glass-visual-skill/` comme racine).
2. Dans Claude : **Personnaliser > Compétences > + > Créer une compétence > Télécharger une compétence**.
3. Importer le ZIP, activer la compétence et formuler une demande qui mentionne `liquid-glass-visual-skill`.

## Installer dans Claude Code

Copier **uniquement** le dossier `liquid-glass-visual-skill/` dans :

- `~/.claude/skills/liquid-glass-visual-skill/` pour un usage utilisateur global, ou
- `.claude/skills/liquid-glass-visual-skill/` dans un projet **si vous choisissez délibérément de l'inclure dans ce projet**.

Pour garder le dépôt de l'application intact, privilégiez l'installation utilisateur globale. Vous pourrez alors invoquer `/liquid-glass-visual-skill` ou demander explicitement à Claude de l'appliquer. Les versions et interfaces de Claude évoluent ; voir les ressources Anthropic dans `SOURCES.md`.

## Application à AtherShell Alpha 4

Le fichier `PROMPT_ATHERSHELL_ALPHA4.md` propose une demande prête à coller. Elle demande à Claude de découvrir **l'architecture réelle du projet** avant d'intervenir, de préserver le thème Grain et de travailler uniquement le thème Liquid.

## Critères et limites

Les comportements de Liquid Glass décrits par Apple sont une **référence de design**. Aucun moteur, shader, source Apple ou image Apple n'est distribué ici. Les seuils WCAG 2.2 AA font partie de nos exigences de qualité, sans être attribués à Apple.

## Publication indépendante sur GitHub

Créer un **nouveau dépôt PUBLIC** nommé par exemple `liquid-glass-visual-skill` dans le bon compte GitHub. Ne pas sélectionner le dépôt AtherShell. Extraire l'archive **GitHub** puis téléverser le contenu extrait (`README.md`, `LICENSE`, `PROMPT_ATHERSHELL_ALPHA4.md`, et le dossier du skill). Un ZIP téléversé sans extraction resterait un simple fichier ZIP.

## Licence

MIT pour les fichiers originaux de ce projet. Apple et Liquid Glass sont des marques ou désignations appartenant à leurs titulaires respectifs. Ce dépôt n'est ni affilié ni approuvé par Apple.