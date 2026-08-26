# 2D Stealth Puzzle Game (C++ / SFML)
A lightweight, high-performance 2D stealth puzzle game built from scratch using C++ and the SFML library. This project focuses on custom engine architecture, object-oriented design, and predictable game-loop state management.

Gameplay Preview 

## Gameplay Features
- Cinematic Intro: Scripted automatic sequence where a persistent enemy chases the player into the starting area.
- Stealth Mechanics: A dynamic NPC dog system with multiple behaviors governed by a clean switch-case logic (Sitting, Barking, Running, Alert, Distracted).
- Item Interaction: Bait-and-distract system to neutralize threats and bypass obstacles.
- Dynamic Level Progression: Event-driven exits that unlock conditionally based on NPC states, preventing out-of-bounds array crashes.

## Architectural Highlights
- Entity Architecture: Core 'Entity' base class governing physics, gravity, and spatial sizing for all game objects.
- Finite State Machine (FSM): Strict and clean separation of game loop cycles (MAINMENU, INTRO, PLAY, GAMEOVER, WIN).
- Custom Collision Matrix: Lightweight AABB (Axis-Aligned Bounding Box) logic driving tile-based physics and conditional win/loss trigger zones.
- View/Camera System: Interpolated screen tracking anchored to player context, with seamless canvas resetting for UI screens.

## Tech Stack
- Language: C++17 / C++20
- Graphics & Windowing: SFML (Simple and Fast Multimedia Library)
- IDE: Microsoft Visual Studio