# Interactive Storytelling Adventure Game

Welcome to the Interactive Storytelling Adventure Game!!! This game allows players to immerse themselves in a captivating narrative, make choices, and solve puzzles as they journey through various scenes and challenges.

## Table of Contents

- [Project Description](#project-description)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Gameplay](#gameplay)
- [Contribution](#contribution)
- [License](#license)
- [Acknowledgements](#acknowledgements)

## Project Description

This project is a text-based adventure game built in C. Players navigate through an intricate storyline filled with puzzles and choices, interacting with unique characters and uncovering hidden secrets.

## Features

- **Engaging Storyline**: Dive into a rich narrative with well-crafted scenes and characters.
- **Interactive Choices**: Make decisions that influence the outcome of the story.
- **Puzzles and Riddles**: Solve challenging puzzles to progress through the game.
- **Colorful Text**: Enjoy a visually appealing text display with color-coded dialogues and descriptions.

## Installation

To install and run the game, follow these steps:

1. **Clone the Repository**:
    ```bash
	git clone https://github.com/Coll76/Kamilimu_Month3/.git
    ```
    ```
2. **Navigate to the Project Directory**:
    ```bash
    cd interactive-storytelling-game
    ```
3. **Compile the Source Code**:
    ```bash
    gcc main.c -o adventure_game -lmicrohttpd
    ```
4. **Run the Game**:
    ```bash
    ./adventure_game
    ```

## Usage

Once the game is running, follow the on-screen prompts to make choices and progress through the story. Use your intuition and problem-solving skills to solve puzzles and uncover secrets.

## Gameplay

### Starting the Game

Upon launching the game, you'll be introduced to the protagonist, Cipher, and the world of Veridium. Follow the prompts to interact with characters and make choices.

### Making Choices

Throughout the game, you'll be presented with multiple-choice questions and interactive scenarios. Your choices will determine the direction of the story and its outcome.

### Solving Puzzles

The game features various puzzles and riddles that you must solve to advance. Pay close attention to the clues provided in the dialogues and descriptions.

### Example

Here’s a snippet of how the game might look:

```c
printf("\nTrusting Lexicon's Whispered Lore\n\n");

printf("#### Scene: The Arcane Library\n\n");
printf("The air in the Arcane Library hung heavy with the scent of ancient parchment.\n");
printf("Cipher stood before Professor Lexicon, their heart racing.\n");
printf("Lexicon's eyes bore into Cipher's soul, assessing their resolve.\n\n");

printf("1. **Cipher:** \"Professor Lexicon, I trust your wisdom.\n");
printf("Share the secrets of the Eidolon Codex with me.\"\n\n");

printf("2. **Lexicon:** \"Ah, trust—a fragile thread woven through time.\n");
printf("Very well, Cipher. The Codex speaks of a forgotten realm—the Nexus of Whispers.\n");
printf("To find it, you must decipher the celestial glyphs etched on the moonstone obelisk in the Whispering Grove.\"\n\n");

printf("#### Scene: The Whispering Grove\n\n");
printf("Moonlight filtered through ancient leaves as Cipher followed Lexicon's cryptic directions.\n");
printf("The obelisk stood tall, its surface adorned with intricate symbols.\n");
printf("Cipher traced their fingers over the glyphs, feeling the pulse of forgotten magic.\n\n");

