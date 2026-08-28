# 2D Dog Platformer — Prototype

A small 2D stealth-platformer prototype built from scratch in **C++** using **SFML**.

This is my **first C++ project**, built while learning game programming fundamentals. It is a technical prototype of the first (tutorial) level from a larger game design concept about a stray dog navigating the streets of a city — full design document available on request / linked in my resume.

The game is currently placeholder-only (no sprites/animations yet — all objects are represented as colored rectangles). The focus of this prototype is **gameplay logic, not visuals**: movement, collision, interaction systems, and a full playable loop from menu to win/lose state.

## Current status

This is a **learning project / prototype**, not a finished game. It represents my current skill level as I study C++ and continue building toward a junior game programmer role.

## Gameplay

The player controls a dog navigating a small level:

* A **guard dog (NPC)** on a leash blocks the path and will scare the player away if approached directly.
* The player must **distract the guard dog with a bone** to get past it.
* Once distracted, an exit path opens: jump onto a doghouse and reach the exit zone to **win**.
* Encountering the **human enemy NPC** ends the game immediately (instant loss) — representing the "capture" threat from the game design.

The full loop is implemented: **Main Menu → Gameplay → Win / Lose → Exit**.

## Controls
- A/D — Move left / right
- Space — Jump
- Ctrl — Crawl
- F — Interact / pick up & carry item

##Project structure
- Entity — Base class for everything placed on the map: the player, both NPCs (dog and human), and items.
- Player — Player-controlled character: movement, states, input handling.
- Dog — NPC — the guard dog on a leash that reacts to the player and can be distracted.
- Enemy — NPC — the human enemy; triggers instant loss on contact.
- DynamicObject — Shared physics/movement behavior for entities that move (velocity, gravity, collision response).
- Item — Pickable objects in the world (e.g. the bone used to distract the dog).
- Carrier — Mouth-carry system — links an entity (the player) to an item it is carrying, separate from general interaction.
- InteractionSystem — Handles general interactions between the player and world objects (excluding carrying).
- Tile / TileMap — Level tiles and the tilemap that assembles them into a level.
- Camera — Follows the player around the level.
- Game — Main game loop, state management (menu, gameplay, win/lose).

## Build

Built with **Visual Studio** (C++) and **SFML**. Open the solution file and build in Visual Studio; make sure SFML is available to the project (via NuGet, vcpkg, or a local SFML install linked in project settings).

## Roadmap

Planned next steps, following the full game design document:

* Sprite/animation replacement for placeholder graphics
* Memory collectible system
* Expanded threat \& perception mechanics (pack dogs, capture counter)
* Multiple endings

## Screenshots / Video

*\[gameplay video / screenshots to be added]*

\---

This project is part of my learning path in game programming. A more advanced version of the same first level is currently being rebuilt in **Unreal Engine** ([Dog\_2.5D](https://github.com/Felorex/Dog_2.5D)) as I continue developing my skills.

