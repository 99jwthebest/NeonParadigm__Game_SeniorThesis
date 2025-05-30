# 🎮 Neon Paradigm

*A hack-and-slash rhythm game where players must strike and dodge to the beat, using dynamic audio and custom shaders to create a fast-paced, immersive experience.*

---

## 📑 Table of Contents

- [Project Description](#project-description)  
- [Core Features](#core-features)  
- [Feature Breakdown](#feature-breakdown)  
- [Technology Used](#technology-used)  
- [Developer Role](#developer-role)  
- [Development Insights](#development-insights)  
- [Demo Preview](#demo-preview) *(optional)*  
- [Key Code Samples](#key-code-samples) *(optional)*  
- [Screenshots](#screenshots) *(optional)*  
- [Getting Started](#getting-started) *(optional)*  
- [License](#license)

---

## 📌 Project Description

**Neon Paradigm** is a senior thesis project developed at the **University of the Incarnate Word**. Built in **Unreal Engine 5 using C++ and Blueprints**, the game combines hack-and-slash action with rhythm mechanics. Players must perform attacks, dodges, and movements **on the beat** to maximize damage, combos, and style.

The game uses **FMOD Studio** for adaptive, dynamic audio — syncing gameplay actions and enemy behavior to music in real time. To further immerse players, **custom shaders** and visual effects react to beats and combos, enhancing moment-to-moment feedback and timing.

This project reflects a complete blend of **gameplay systems programming, real-time audio integration, team collaboration**, and **visual design**.

---

## 🎮 Core Features

- 🎵 **Rhythm-Based Combat** – Players attack/dodge on beat to deal more damage and trigger combo bonuses  
- ⚔️ **Hack-and-Slash Mechanics** – Light/heavy attack chains and beat-timed executions  
- 🔊 **FMOD Integration** – Syncs game events to music via timeline callbacks and beat data  
- ✨ **Custom Shaders** – Post-process and particle effects timed to rhythm and combat events  
- 🧠 **On-Beat Feedback System** – Real-time scoring and input window detection for rhythm accuracy  
- 🎓 **Capstone-Level Scope** – Built for thesis completion, including full technical and creative ownership

---

## ⚙️ Feature Breakdown

| Feature                  | Description                                                                 |
|--------------------------|-----------------------------------------------------------------------------|
| 🎯 Rhythm Input System   | Custom beat tracking and input timing logic synced to FMOD event timeline  |
| 🧱 Modular Combo Chains  | Inheritance-based attack classes with timing-sensitive branching logic     |
| 🧠 Enemy AI               | Telegraphed rhythm-based attacks with animation blending and sync logic     |
| 🔄 FMOD Audio Triggers   | Music triggers FX, enemy waves, and beat-tied gameplay events               |
| 💥 Shader FX             | Beat-reactive post-processing, emissive pulses, and combo visuals           |

---

## 🛠️ Technology Used

- **Unreal Engine 5** – Core engine for game development  
- **C++ & Blueprints** – Gameplay systems, animation control, combat logic  
- **FMOD Studio** – Timeline callbacks, dynamic audio events, tempo syncing  
- **HLSL / Material Editor** – Custom post-process and feedback shaders  
- **GitHub** – Version control and development tracking  
- **Perforce (optional)** – Used locally for backup and file locking (not shared)

---

## 👤 Developer Role

This game was developed by **Joseph Hernandez** as a solo programmer and team lead, with collaboration from other student artists and designers.

- Designed and programmed all core systems (C++, Blueprint)  
- Integrated FMOD and developed beat-based sync architecture  
- Built combat systems using modular inheritance  
- Implemented visual feedback using custom shaders and animation notifies  
- Coordinated with teammates and managed scope/deliverables  
- Optimized gameplay systems for feel, clarity, and audio sync reliability

---

## 🧠 Development Insights

- Developed a custom system for syncing inputs to beat timing using FMOD timeline callbacks  
- Balanced responsiveness and difficulty by fine-tuning input windows and beat tolerance  
- Refactored gameplay logic using OOP principles for maintainability and reuse  
- Worked with animation blueprints and state machines to ensure precise visual feedback  
- Learned FMOD's API deeply to communicate with game state and build real-time audio logic  
- Managed polish phase with shader experimentation and performance testing

---

## 🎥 Demo Preview

*Coming soon* – Video walkthrough or gameplay demo (YouTube or GIF recommended)

---

## 📂 Key Code Samples

*These will link to GitHub repo files once uploaded.*

- `RhythmInputComponent.cpp` – Handles beat validation logic for player inputs  
- `FMODSyncManager.cpp` – Listens to beat markers and triggers in-game events  
- `BaseAttackAction.cpp` – Core attack inheritance class for light/heavy/finisher logic  
- `EnemyAIController.cpp` – Rhythm-aware enemy behavior and telegraphed animations  

---

## 🖼️ Screenshots

*Coming soon*

---

## 🚀 Getting Started

> _Note: This section is optional unless you're distributing the project._

```bash
# Requirements
- Unreal Engine 5.1+
- FMOD Plugin installed
- Clone or fork repository

# To run:
1. Open project in Unreal Engine
2. Regenerate Visual Studio files (if needed)
3. Build and launch in editor
