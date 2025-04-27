# 📜 Project Title: Parallax Scene with Jumping Character (Cocos2d-x Android)

## 📖 Description

This project is a simple parallax scrolling scene built using Cocos2d-x for Android.  
It features:
- A horizontally scrollable background with parallax effect (3 layers: background, character, foreground).
- A character with **idle** animation by default.
- A UI button ("Jump") that triggers a **jump animation** for the character.

---

## 📋 Requirements

- **Cocos2d-x** version: 3.17.2 or 4.0
- **Android Studio**: 4.0 or higher
- **NDK**: r16b or r21e (matching your Cocos2d-x version)
- **Android SDK**: 28 or higher
- **Java**: JDK 8
- Target Device: Android phone or emulator

---

## 🛠 How to Build

1. Install and set up **Cocos2d-x** on your system.
2. Open **Android Studio**.
3. Select **Open an Existing Project** and choose this project folder.
4. Wait for Gradle sync to finish.
5. Make sure your **NDK** path is correctly configured (`local.properties` should have the NDK path).
6. Connect your Android device (or use an emulator).
7. Click **Run** ▶️ to build and deploy the app.

**Note:**  
Make sure that all your assets (sprites, backgrounds, plist files) are placed correctly inside the `Resources/` directory.

---

## 🎮 Features

- **Parallax Scrolling**: Move the scene horizontally by dragging your finger.
- **Idle Animation**: Character plays idle animation continuously.
- **Jump Animation**: Press the "Jump" button to trigger jump animation.

