#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // For usleep function (Unix/Linux)
#include <ctype.h>
#include <microhttpd.h>
#define PORT 8888
#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"
#define PINK "\033[1;35m"


// Define NPC structure to hold their information
typedef struct {
    const char *name;
    int trustLevel;  // Starting trust level
    int dialogueUnlocked;  // Flag to indicate if special dialogue is unlocked
} NPC;




void type_Text(const char *text);
void displayIntroduction();
void exploreRhetoria();
void enterCodehaven();
void climbOratorsPeak();
void handleEthicalDilemma();
void faceFirewallOfTrust();
void debateAtGrandHall();
//void handleRelationships();
void deliverTEDxTalk();
void displayEnding();
void respondToDiplomatChallenge(int response);
void interactWithNPC(NPC *npc);
void displayStory(const char *chapter);
void handleRelationships(NPC *npc, const char *interaction);
void handleChoices();
void typeText(const char *text);
void trustProfessorLexicon();
int checkAnswer(const char* correctAnswer);
void typeText_(const char* text);
void deliverTEDxTalk();
char *read_html_file(const char *filename);
struct MHD_Daemon *start_web_server();
void stop_web_server(struct MHD_Daemon *web_server_daemon);
static enum MHD_Result answer_to_connection(void *cls, struct MHD_Connection *connection,
                                            const char *url, const char *method,
                                            const char *version, const char *upload_data,
                                            size_t *upload_data_size, void **con_cls);
// Global variables

int eloquencePoints = 0;  // Track player's eloquence points
void deliverTEDxTalk();

struct MHD_Daemon *web_server_instance = NULL; // Global variable to store the server instance

int main() {
    int choice;
    
    //handleChoices();
    //displayIntroduction();

    // Start the web server in a separate thread
    start_web_server();

    do {
        printf(BLUE"\n------------------------------\n"RESET);
        printf(CYAN"Choose your next action:\n\n");
        printf("1. Explore Rhetoria\n\n");
        printf("2. Enter Codehaven\n\n");
        printf("3. Climb Orator's Peak\n\n");
        printf("4. Manage Relationships\n\n");
        printf("5. Deliver TEDx Talk\n\n");
        printf("0. Quit\n\n"RESET);
        printf(RED"Enter your choice: "RESET);
        scanf("%d", &choice);
        printf(BLUE"------------------------------\n\n"RESET);

        switch(choice) {
            case 1:
                exploreRhetoria();
                break;
            case 2:
                enterCodehaven();
                break;
            case 3:
                climbOratorsPeak();
                break;
            case 4:
                handleChoices();
                break;
            case 5:
                deliverTEDxTalk();
                break;
            case 0:
                displayEnding();
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while(choice != 0);
    stop_web_server(web_server_instance);
    return 0;
}


void respondToDiplomatChallenge(int response) {
    switch (response) {
        case 1:
            typeText(MAGENTA"\nAs the diplomat raises their concerns, you maintain eye contact and nod thoughtfully.\n\n");
            typeText("You acknowledge the historical pitfalls of empathy in diplomacy, but with conviction, you respond:\n\n");
            typeText("\"Indeed, empathy can be a double-edged sword. However, it's essential to recognize that true diplomacy transcends mere transactions.\"\n\n");
            typeText("\"Empathy fosters trust, understanding, and lasting relationships. It allows us to see beyond national interests to shared humanity.\"\n\n");
            typeText("\"Remember the Cuban Missile Crisis? Kennedy's empathetic approach helped avert catastrophe.\"\n\n"RESET);
            break;
        case 2:
            typeText(MAGENTA"\nYou lean forward, your voice steady and confident.\n");
            typeText("\"While empathy may seem soft, it has wielded immense power in diplomatic history.\"\n\n");
            typeText("\"Consider Nelson Mandela's reconciliation efforts in post-apartheid South Africa. His empathy bridged deep divides.\"\n\n");
            typeText("\"And let's not forget Sadat and Begin, who found common ground through empathy at Camp David.\"\n\n"RESET);
            break;
        case 3:
            typeText(MAGENTA"\nWith a diplomatic smile, you extend your hand to the distinguished diplomat.\n\n");
            typeText("\"Your perspective is valuable,\" you say. \"Let's collaborate on a balanced approach.\"\n\n");
            typeText("\"Empathy need not weaken negotiations; it can be our compass toward win-win solutions.\"\n\n"RESET);
            break;
        default:
            printf("\nOops! That's not a valid response. Remember, diplomacy requires adaptability.\n");
    }
}

void interactWithNPC(NPC *npc) {

int choice;

    printf(RED"\nYou encounter %s. What do you do?\nRESET", npc->name);

    printf("\n---\n");
    printf(CYAN"Interacting with %s\n", npc->name);
    printf("1. Trust %s\n\n", npc->name);
    printf("2. Question %s\n\n"RESET, npc->name);
    //printf("3. Solve %s's Puzzle\n\n", npc->name);
    //printf("4. Refuse %s's Puzzle\n\n", npc->name);
    //printf("5. Share Story with %s\n\n", npc->name);
    //printf("6. Keep Secrets from %s\n\n", npc->name);
    printf(RED"Enter your choice: "RESET);
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            handleRelationships(npc, "trust");
            if (strcmp(npc->name, "Professor Lexicon") == 0) {
		trustProfessorLexicon();
}
	    //trustProfessorLexicon();
            break;
        case 2:
            handleRelationships(npc, "question");
            if (strcmp(npc->name, "Professor Lexicon") == 0) {
                typeText("\nCipher’s intuition whispers caution. They probe Lexicon’s motives, seeking cracks in the icy facade. Lexicon’s eyes flicker—perhaps with admiration for Cipher’s discernment. Secrets unravel: Lexicon’s past, their own longing, and the fragile threads connecting worlds. But can Cipher decipher truth from deception?\n");
            }
            break;
        case 3:
            handleRelationships(npc, "solve");
            typeText("\nCipher dives into Byte's code to solve the algorithm.\n");
            break;
        case 4:
            handleRelationships(npc, "refuse");
            typeText("\nCipher refuses Byte's request to solve the algorithm.\n");
            break;
        case 5:
            handleRelationships(npc, "share");
            typeText("\nCipher confides in Eloquence, sharing their experiences.\n");
            break;
        case 6:
            handleRelationships(npc, "keep_secret");
            typeText("\nCipher chooses to keep their past hidden from Eloquence.\n");
            break;
        default:
            typeText("\nInvalid choice. Please select a valid option.\n");
            break;
    }
}



// Function to manage NPC relationships
void handleRelationships(NPC *npc, const char *interaction) {
    if (strcmp(interaction, "trust") == 0) {
        npc->trustLevel += 10;
    } else if (strcmp(interaction, "question") == 0) {
        npc->trustLevel -= 5;
    } else if (strcmp(interaction, "solve") == 0) {
        npc->trustLevel += 15;
    } else if (strcmp(interaction, "refuse") == 0) {
        npc->trustLevel -= 10;
    } else if (strcmp(interaction, "share") == 0) {
        npc->trustLevel += 15;
    } else if (strcmp(interaction, "keep_secret") == 0) {
        npc->trustLevel -= 5;
    }

    // Ensure trust level stays within bounds
    if (npc->trustLevel > 100) {
        npc->trustLevel = 100;
    } else if (npc->trustLevel < 0) {
        npc->trustLevel = 0;
    }

    printf("%s's trust level is now %d.\n", npc->name, npc->trustLevel);
}



int checkAnswer(const char* correctAnswer) {
    char playerResponse[100]; // Assuming a reasonable maximum length for the answer
    typeText(RED"\nEnter your answer: "RESET);
    scanf(" %[^\n]", playerResponse);

    // Convert to lowercase for case-insensitive comparison
    for (int i = 0; playerResponse[i]; i++) {
        playerResponse[i] = tolower(playerResponse[i]);
    }

    // Validate the player's answer
    return strcmp(playerResponse, correctAnswer) == 0;
}



void trustProfessorLexicon() {
    // Detailed scenario for trusting Professor Lexicon
    typeText(CYAN "\nTrusting Lexicon's Whispered Lore\n\n" RESET);

typeText("\n#### Scene: The Arcane Library\n\n" RESET);

typeText("\nThe air in the Arcane Library hung heavy with the scent of ancient parchment.\n");
typeText("Cipher stood before Professor Lexicon, their heart racing.\n");
typeText("Lexicon's eyes bore into Cipher's soul, assessing their resolve.\n\n");

typeText(MAGENTA "\n1. **Cipher:** \"Professor Lexicon, I trust your wisdom.\n");
typeText("Share the secrets of the Eidolon Codex with me.\"\n\n");

typeText("\n2. **Lexicon:** \"Ah, trust—a fragile thread woven through time.\n");
typeText("Very well, Cipher. The Codex speaks of a forgotten realm—the Nexus of Whispers.\n");
typeText("To find it, you must decipher the celestial glyphs etched on the moonstone obelisk in the Whispering Grove.\"\n\n" RESET);

typeText(CYAN "\n#### Scene: The Whispering Grove\n\n" RESET);

typeText("\nMoonlight filtered through ancient leaves as Cipher followed Lexicon's cryptic directions.\n");
typeText("The obelisk stood tall, its surface adorned with intricate symbols.\n");
typeText("Cipher traced their fingers over the glyphs, feeling the pulse of forgotten magic.\n\n");

    // Proverb challenges
    int correctAnswers = 0;

    while (correctAnswers < 3) {
        switch (correctAnswers) {
            case 0:
    typeText(CYAN "\n**The First Proverb**\n\n" RESET);
    typeText(MAGENTA "\n1. **Voice of the Nexus:** \"Cipher, seeker of truths, listen well.\n\n"RESET);
    typeText(RED"In the dance of words, what bridges gaps and mends hearts?\"\n\n"RESET);
    typeText("\nThe moonstone glows brighter, revealing a path strewn with luminescent petals.\n\n");
    typeText("Cipher follows, heart pounding.\n\n" RESET);

    if (checkAnswer("communication")) {
        typeText("\nCongratulations! You have correctly deciphered the first proverb.\n\n");
        typeText("The moonstone pathway glows brighter, guiding you deeper into the Nexus of Whispers.\n\n");
        correctAnswers++;
    } else {
        typeText("\nIncorrect. The Nexus's whispers grow fainter, urging you to reconsider your answer.\n\n");
    }
    break;

case 1:
    typeText(CYAN "\n**The Second Riddle**\n\n" RESET);
    typeText(GREEN "\n1. **Voice of the Nexus:** \"Cipher, unravel this enigma:\n\n");
    typeText(RED"'I speak without a mouth, hear without ears, and am everywhere. What am I?'\"\n\n"RESET);
    typeText("\nThe path twists, leading deeper into the garden.\n\n");
    typeText("Cipher's determination grows.\n\n" RESET);

    if (checkAnswer("thought")) {
        typeText(GREEN "\nCongratulations! You have correctly deciphered the second riddle.\n");
        typeText("The garden's mysteries unfold before you.\n\n" RESET);
        correctAnswers++;
    } else {
        typeText(RED"\nIncorrect. The enigma lingers, challenging your understanding.\n\n" RESET);
    }
    break;

case 2:
    typeText(CYAN "\n**The Third Proverb**\n\n" RESET);
    typeText(MAGENTA"\n1. **Voice of the Nexus:** \"Cipher, decipher this metaphor:\n"RESET);
    typeText(RED"'A quill dipped in empathy writes the most eloquent letters.' What does it mean?\"\n" RESET);

    if (checkAnswer("empathy")) {
        typeText(GREEN "\nCongratulations! You have correctly deciphered the third proverb.\n");
        typeText("The scroll's wisdom shines upon you.\n" RESET);
        correctAnswers++;
    } else {
        typeText(RED "\nIncorrect. The metaphor's essence eludes your grasp.\n" RESET);
    }
    break;

  default:
                typeText(RED"\nInvalid choice. Please enter a valid number.\n"RESET);
                break;
        }
    }

    type_Text(CYAN"\n#### The Forbidden Knowledge\n\n"RESET);
    type_Text(MAGENTA"\nCipher unrolls the scroll, eyes scanning the elegant script:\n\n");
    type_Text("\n> **The Art of Professional Communication: A Celestial Guide**\n\n");
    type_Text("\n> 1. **Listen Like the Wind**: Understand before being understood. Active listening bridges gaps.\n\n");
    type_Text("\n> 2. **Speak with Constellations**: Choose words wisely. Each syllable shapes galaxies of meaning.\n\n");
    type_Text("\n> 3. **Navigate Nebulas of Conflict**: Diplomacy steers through tempests. Seek common orbits.\n\n");
    type_Text("\n> 4. **Compose Stellar Emails**: Clarity, brevity, and warmth—like sunbeams through clouds.\n\n");
    type_Text("\n> 5. **Telepathy via PowerPoint**: Visuals speak louder than nebulous slides. Illuminate ideas.\n\n");
    type_Text("\n> 6. **Celestial Networking**: Connect orbits, not just stars. Nurture relationships.\n\n");
    type_Text("\n> 7. **Cosmic Etiquette**: Respect orbits—time, space, and boundaries.\n\n");
    type_Text("\n> Remember, Cipher: The universe listens to eloquence. May your words echo among the stars.\n\n"RESET);
}






void handleChoices() {
    // Display Chapter 1
    displayStory("Chapter 1");

    // Create NPCs
    NPC lexicon = {"Professor Lexicon", 50};
    NPC byte = {"Byte", 50};
    NPC eloquence = {"Eloquence", 50};

    // Interact with each NPC
    interactWithNPC(&lexicon);
    //interactWithNPC(&byte);
    //interactWithNPC(&eloquence);

    // Add more chapters and choices as needed
}




void typeText(const char *text) {
    // ANSI escape code for green text
    printf("\033[0;32m");
    while (*text) {
        putchar(*text++);
        fflush(stdout); // Ensure each character is printed immediately
        usleep(50000); // 50 milliseconds delay (adjust as needed)
    }
    // Reset ANSI color
    printf("\033[0m");
}

void type_Text(const char *text) {
    // ANSI escape code for green text
    printf("\033[0;35;1m");
    while (*text) {
        putchar(*text++);
        fflush(stdout); // Ensure each character is printed immediately
        usleep(50000); // 50 milliseconds delay (adjust as needed)
    }
    // Reset ANSI color
    printf("\033[0m");
}


void typeText_(const char *text) {
    // ANSI escape code for shouting yellow paragragh
    printf("\033[1;33m"); // Bold yellow text

    // Create a modifiable copy of the input text for tokenization
    char *textCopy = malloc(strlen(text) + 1);
    if (textCopy == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    strcpy(textCopy, text);

    // Paragraph delimiter
    const char *delimiter = "\n\n";
    char *token = strtok(textCopy, delimiter);
    int delay = 1000; // Delay in milliseconds (adjust as needed)

    while (token != NULL) {
        // Print the paragraph
        printf("%s\n\n", token);
        fflush(stdout); // Ensure immediate output

        // Delay before printing the next paragraph
        usleep(delay * 1000); // Delay in microseconds

        // Get the next paragraph token
        token = strtok(NULL, delimiter);
    }

    printf("\033[0m"); // Reset ANSI color

    free(textCopy); // Free the allocated memory
}


void displayStory(const char *chapter) {
    if (strcmp(chapter, "Chapter 1") == 0) {
    printf("## The Chronicles of Lexicon, Byte, and Eloquence\n\n");

    printf("### Chapter 1: The Enigma of the Ancient Script\n\n");
    printf(RESET);
    printf(MAGENTA "In the sprawling city of Veridium, where steam-powered airships sailed between towering spires,\n\n");
    printf("our protagonist—known only as \"Cipher\"—embarked on a quest that would unravel secrets hidden for centuries.\n\n");

    printf("#### 1. Professor Lexicon's Mysterious Research\n\n");

    printf("Professor Lexicon, a reclusive scholar with ink-stained fingers and a penchant for dusty tomes,\n\n");
    printf("guarded the archives of the Arcane Library. Their eyes held the wisdom of ages,\n\n");
    printf("but their heart remained locked away. Cipher approached Lexicon,\n\n");
    printf("determined to break through the icy facade.\n\n");

    printf("\"Greetings, Professor,\" Cipher said,\n\n");
    printf("their voice echoing in the dimly lit chamber.\n\n");
    printf("\"I've heard whispers of an ancient script—the 'Eidolon Codex.' Can you guide me?\"\n\n");

    printf("Lexicon's gaze flickered. \"Curious, aren't you?\n\n");
    printf("Few seek the Codex. It holds forbidden knowledge—the key to realms beyond our own.\n\n");
    printf("But trust is earned, not given.\"\n\n");

    printf("And so, Cipher embarked on a quest:\n\n");
    printf("deciphering glyphs, piecing together fragments, and earning Lexicon's trust.\n\n");
    printf("As days turned into weeks, Lexicon's stern demeanor softened.\n\n");
    printf("They shared tales of lost civilizations, star maps, and forgotten gods.\n\n");
}
}


void climbOratorsPeak() {
    printf(MAGENTA"You climb the treacherous cliffs of Orator's Peak...\n\n");
    printf("Confront your fear of public speaking at the Summit of Eloquence...\n\n");
    printf("Craft speeches on responsible technology, empathy, and global harmony...\n\n");

    // Simulate a public speaking challenge
    printf("\nYou are challenged to speak at the Grand Debate Hall...\n\n");
    printf("Topic: 'The Role of Empathy in Global Diplomacy'\n\n");
    printf("Prepare your speech:\n\n"RESET);
    

    int choice;
    int previousChoice = 0; // Variable to store previous valid choice
    char speech[500]; // Assuming a maximum speech length of 500 characters
    printf(RED "Enter your speech (max 500 characters):\n\n" RESET);
        typeText(CYAN "#######################################\n\n" RESET);
	getchar(); // Consume the newline character left by previous scanf
	fgets(speech, sizeof(speech), stdin);
	printf(BLUE "\nYou have prepared your speech:\n" RESET);
        printf("%s\n", speech);
	typeText(MAGENTA "\nThe audience listens attentively...\n\n" RESET);
		       //
    do {
        // Offer choices to the player
        printf(CYAN "How do you engage the audience?\n\n");
        printf("1. Use emotional appeal to connect with their empathy.\n\n");
        printf("2. Present factual evidence to support your arguments.\n\n");
        printf("3. Invite audience participation with a thought-provoking question.\n\n");
        printf("4. Back to main menu.\n\n");
        printf("\n" RESET);
        printf(RED "Enter your choice (1-4): " RESET);
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                typeText(MAGENTA "\nYou connect deeply with the audience's emotions, gaining their empathy.\n" RESET);
                break;
            case 2:
                typeText(MAGENTA "\nYour evidence-based approach impresses the audience with solid arguments.\n" RESET);
                break;
            case 3:
                typeText(MAGENTA "\nThe auditorium buzzes with energy as diverse viewpoints converge.\n\n");
                typeText("A symphony of voices rises—some harmonizing, others dissonant, yet all essential.\n" RESET);
                break;
            case 4:
                printf(RED "\nReturning to main menu...\n" RESET);
                return; // Exit the current function and return to the main menu
            default:
                typeText(MAGENTA "\nInvalid choice. Please enter a number between 1 and 4.\n" RESET);
                break;
        }
    } while (choice < 1 || choice > 4);

    typeText("-------------------------------\n\n");

    typeText(CYAN "Intermezzo: The Art of Silence\n\n" RESET);
    typeText("Between choices, there lies silence—a canvas awaiting brushstrokes.\n\n");
    typeText("You pause, eyes scanning the room.\n\n");
    typeText("The audience leans forward, breath held.\n\n");
    typeText("In this pregnant hush, you become a conductor—orchestrating emotions, weaving connections.\n\n");
    typeText("The unseen threads tighten.\n\n");

    typeText("-------------------------------\n\n");

    typeText(CYAN "Act II: The Climax\n\n" RESET);
    typeText("Your choice echoes through the hall.\n\n");
    typeText("The audience leans into your narrative, hungry for more.\n\n");
    typeText("You've engaged them, but this is no monologue—it's a dialogue, a dance.\n\n");
    typeText("You share vulnerability, they offer empathy.\n\n");
    typeText("You present facts, they nod in agreement.\n\n");
    typeText("You ask questions, they lean into uncertainty.\n\n");

    typeText("And then, the crescendo—the moment when hearts align, when minds spark, when the ordinary becomes extraordinary.\n\n");
    typeText("You've engaged them not by force, but by invitation.\n\n");
    typeText("They leave with seeds planted—ideas to nurture, connections to explore.\n\n");

    typeText("-------------------------------\n\n");

    typeText(CYAN "Epilogue: The Unseen Applause\n\n" RESET);
    printf(MAGENTA"As the curtain descends, remember this: Engagement isn't a formula; it's an alchemical blend of vulnerability, rigor, and wonder.\n\n");
    printf("The audience—your co-creators—will carry your words beyond this stage.\n\n");
    printf("They'll debate, dream, and perhaps, change the world.\n\n"RESET);

    // Simulate a rebuttal scenario or debate interaction
    printf(MAGENTA"\nAfter your speech, a distinguished diplomat challenges your stance on empathy in diplomacy...\n\n");
    printf("They argue that empathy can sometimes weaken diplomatic negotiations, citing historical examples.\n\n"RESET);
    typeText(RED"How do you respond?\n\n"RESET);
    printf(CYAN"1. Acknowledge the challenges but emphasize empathy's role in fostering trust and understanding.\n\n");
    printf("2. Counter with examples where empathy led to successful diplomatic outcomes.\n\n");
    printf("3. Invite the diplomat to collaborate on finding a balanced approach.\n\n"RESET);
    printf(RED"Enter your response (1-3): "RESET);
    int response;
    scanf("%d", &response);

    respondToDiplomatChallenge(response);

    // Additional challenges or interactions can be added here
    typeText(MAGENTA"\nYou leave the Grand Debate Hall, reflecting on the exchange and your growing eloquence...\n"RESET);
}




void displayIntroduction() {
    printf("Welcome to 'The Quest for Eloquence'!\n");
    printf("You find yourself in the mystical land of Verbalia...\n");
    printf("Your mission: to become an eloquent speaker by mastering communication,\n");
    printf("building relationships, and conquering linguistic challenges.\n");
}

void exploreRhetoria() {
    printf(BOLD PINK"You enter the lush forests of Rhetoria...\n");
    printf("Ancient sages teach you the secrets of persuasive speech.\n");
    printf("Engage in debates with mythical creatures...\n");
    printf("Collect 'Golden Phrases' that unlock hidden paths.\n");

    // Simulate a debate scenario
    printf("\nYou encounter the Sphinx of Rhetoric...\n");
    printf("It challenges you with a riddle:\n");
    printf("\"What is the most powerful rhetorical device?\"\n"RESET);
    printf(BOLD YELLOW"Your answer: ");
    char answer[50];
    scanf(" %[^\n]", answer);
    if (strcmp(answer, "Pathos") == 0 || strcmp(answer, "pathos") == 0) {
        printf("\nCorrect! The Sphinx is impressed.\n");
        eloquencePoints += 10; // Increase eloquence points
    } else {
        printf("\nIncorrect. The Sphinx sends you on a detour through the labyrinth of words.\n");
        // Implement maze or retry scenario
    }
}

void enterCodehaven() {
    printf("You descend into the cryptic caves of Codehaven...\n");
    printf("Solve programming puzzles to unlock gates...\n");
    printf("Befriend the enigmatic AI guardian, Syntax...\n");

    // Simulate an ethical coding challenge
    printf("\nThe Firewall of Trust blocks your path...\n");
    printf("It demands an ethical algorithm to proceed:\n");
    printf("Write a code snippet that respects user privacy and avoids bias:\n");

    // Example ethical code
    printf("#include <stdio.h>\n");
    printf("int main() {\n");
    printf("    // Your ethical code here...\n");
    printf("    return 0;\n");
    printf("}\n");

    // Additional challenges and interactions
}

/**void climbOratorsPeak() {
    printf("You climb the treacherous cliffs of Orator's Peak...\n");
    printf("Confront your fear of public speaking at the Summit of Eloquence...\n");
    printf("Craft speeches on responsible technology, empathy, and global harmony...\n");

    // Simulate a public speaking challenge
    printf("\nYou are challenged to speak at the Grand Debate Hall...\n");
    printf("Topic: 'The Role of Empathy in Global Diplomacy'\n");
    printf("Prepare your speech:\n");

    // Player's speech preparation (input handling)
}
**/

struct MHD_Daemon *start_web_server() {
    if (web_server_instance != NULL) {
        // Server is already running
        return web_server_instance;
    }

    // Start the web server on the specified port
    web_server_instance = MHD_start_daemon(MHD_USE_SELECT_INTERNALLY, PORT, NULL, NULL,
                              &answer_to_connection, NULL, MHD_OPTION_END);

    if (web_server_instance == NULL) {
        fprintf(stderr, "Error starting server on port %d\n", PORT);
        exit(EXIT_FAILURE);
    }

    printf("Web server started on port %d\n", PORT);

    return web_server_instance;
}

// Function to stop the web server
void stop_web_server(struct MHD_Daemon *web_server_instance) {
    if (web_server_instance != NULL) {
        MHD_stop_daemon(web_server_instance);
        printf("Web server stopped\n");
        web_server_instance = NULL; // Reset the global variable
    }
}

// Function to read content from an HTML file
char *read_html_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *buffer = (char *)malloc(file_size + 1);
    if (!buffer) {
        fclose(fp);
        perror("Memory allocation failed");
        return NULL;
    }

    fread(buffer, 1, file_size, fp);
    fclose(fp);
    buffer[file_size] = '\0';

    return buffer;
}

// Function to handle incoming HTTP connections
static enum MHD_Result answer_to_connection(void *cls, struct MHD_Connection *connection,
                                            const char *url, const char *method,
                                            const char *version, const char *upload_data,
                                            size_t *upload_data_size, void **con_cls) {
    struct MHD_Response *response;
    int ret;

    // Check if the request method is GET and the URL is "/"
    if (0 == strcmp(method, "GET") && 0 == strcmp(url, "/")) {
        // Read content from tedx.html file
        char *file_content = read_html_file("tedx.html");

        // Check if content was read successfully
        if (file_content != NULL) {
            response = MHD_create_response_from_buffer(strlen(file_content), (void *)file_content, MHD_RESPMEM_MUST_FREE);
            ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
            MHD_destroy_response(response);
            // No need to free file_content here, as it is managed by MHD_RESPMEM_MUST_FREE
            return ret;
        } else {
            const char *not_found = "<html><body><h1>File not found or error reading file</h1></body></html>";
            response = MHD_create_response_from_buffer(strlen(not_found), (void *)not_found, MHD_RESPMEM_PERSISTENT);
            ret = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
            MHD_destroy_response(response);
            return ret;
        }
    } else {
        const char *not_found = "<html><body><h1>Not Found</h1></body></html>";
        response = MHD_create_response_from_buffer(strlen(not_found), (void *)not_found, MHD_RESPMEM_PERSISTENT);
        ret = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
        MHD_destroy_response(response);
        return ret;
    }
}

// Function to deliver a TEDx talk
void deliverTEDxTalk() {
    // Start the web server if not already started
    if (web_server_instance == NULL) {
        web_server_instance = start_web_server();
    }

    printf("Delivering TEDx talk...\n");
    printf("Open your browser and go to http://localhost:%d to view the TEDx talks.\n", PORT);
}

void faceFirewallOfTrust() {
    printf("In Codehaven, you confront the Firewall of Trust...\n");
    printf("Write ethical code to balance efficiency and privacy...\n");

    // Ethical coding scenario
}

void debateAtGrandHall() {
    printf("At Orator's Peak, you participate in debates with historical figures...\n");
    printf("Use evidence, empathy, and respectful discourse to gain eloquence points...\n");

    // Debate scenario
}







void displayEnding() {
    // Display different endings based on player's achievements
    if (eloquencePoints >= 50) {
        printf("Congratulations! You have become the Chief Orator of Verbalia,\n");
        printf("inspiring peace and understanding through your eloquence.\n");
    } else {
        printf("You have failed to balance ethics, relationships, and eloquence.\n");
        printf("Wander the linguistic wilderness forever, muttering half-formed sentences.\n");
    }
}
