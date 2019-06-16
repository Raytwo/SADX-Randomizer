#include <algorithm>
#include "SADXVariables.h"
#include "SADXEnums.h"
#include "RandomHelpers.h"
#include "Utils.h"
#include "MemAccess.h"
#include "SADXFunctions.h"
#include "MemAccess.h"

extern bool RNGCharacters;
extern bool RNGStages;
extern bool Regular;


extern "C"
{
	//Set up several arrays, the "level" one doesn't include some specific stages impossible to beat.
	int character[6] = { 0, 2, 3, 5, 6, 7 };
	int CharacterCopy = -1; //Used to avoid getting the same character twice in a row.
	int level[18] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 15, 16, 20, 21, 22, 23, 38 };
<<<<<<< HEAD
	int door[5] = { 0, 1, 2, 3, 4 };
	int metalsonicrng[2] = { 0, 1 };

	//Initialize Banned stage impossible to beat
	int bannedLevelsGamma[8] = { 3, 15, 16, 18, 20, 21, 23, 38 };
	int bannedLevelsBig[3] = { 8, 22, 38 };
	int bannedLevelsAmy[1] = { 38 };
	int bannedLevelsTails[1] = { 5 };

	//Initiliaze banned regular stage if option is activated
	int bannedRegularSonic[10] = { 2, 3, 5, 6, 7, 8, 9, 15, 20, 22 };
	int bannedRegularTails[5] = { 4, 5, 20, 21, 38 };
	int bannedRegularKnuckles[1] = { 16 };
	int bannedRegularAmy[3] = { 12, 23, 38 };
	int bannedRegularBig[3] = { 8, 22, 38 };
	int bannedRegularGamma[8] = { 3, 15, 16, 18, 20, 21, 23, 38 };

=======
	int door[5] = { 0, 1, 2, 3, 4 }; //set up the 5 doors RNG at Final Egg.
	int metalsonicrng[2] = { 0, 1 }; //Used to randomize Metal Sonic.

	//Initialize Ban few stage impossible to beat, depending on the character.
	int bannedLevelsGamma[8] = { 3, 15, 16, 17, 18, 20, 21, 23 };
	int bannedLevelsBig[2] = { 8, 22 };

	//Initiliaze banned regular stage if option is activated
	int bannedRegularSonic[9] = { 2, 5, 6, 7, 8, 15, 17, 20, 22 };
	int bannedRegularTails[5] = { 6, 17, 20, 21, 38 };
	int bannedRegularKnuckles[2] = { 16, 17 };
	int bannedRegularAmy[1] = { 23 };
	int bannedRegularBig[2] = { 8, 22 };
	int bannedRegularGamma[8] = { 3, 15, 16, 17, 18, 20, 21, 23 };
>>>>>>> 2abc2642de7a4355bb7c3faaa42106b4466908a6

	DataPointer(char, Emblem, 0x974AE0);

	//function Randomize stage and characters
	void randomstage(char stage, char act) {
<<<<<<< HEAD
		// Starts the Credits once the player gets 10 Emblems. 
		if (Emblem == 10 || Emblem == 15 || Emblem == 20 || Emblem == 23 || Emblem == 27 || Emblem == 32 || Emblem == 33)
		{
			EventFlagArray[EventFlags_SonicAdventureComplete] = true;
			EventFlagArray[EventFlags_TailsUnlockedAdventure] = true;
			EventFlagArray[EventFlags_KnucklesUnlockedAdventure] = true;
			EventFlagArray[EventFlags_AmyUnlockedAdventure] = true;
			EventFlagArray[EventFlags_BigUnlockedAdventure] = true;
			EventFlagArray[EventFlags_GammaUnlockedAdventure] = true;
			GameMode = GameModes_StartCredits;
			GameState = 21;
			Credits_State = 1;
			CurrentCharacter = 0;
=======

		LastLevel = CurrentLevel;
		LastAct = CurrentAct;

		if (Emblem == 10 || Emblem == 16 || Emblem == 22 || Emblem == 26 || Emblem == 31 || Emblem == 37 || Emblem == 39)
		{
			switch (SelectedCharacter)
			{
			case 0:
				EventFlagArray[EventFlags_SonicAdventureComplete] = true;
				EventFlagArray[EventFlags_TailsUnlockedAdventure] = true;
				EventFlagArray[EventFlags_KnucklesUnlockedAdventure] = true;
				EventFlagArray[EventFlags_AmyUnlockedAdventure] = true;
				EventFlagArray[EventFlags_BigUnlockedAdventure] = true;
				EventFlagArray[EventFlags_GammaUnlockedAdventure] = true;
				break;
			case 1:
				EventFlagArray[EventFlags_TailsAdventureComplete] = true;
				EventFlagArray[EventFlags_KnucklesUnlockedAdventure] = true;
				EventFlagArray[EventFlags_AmyUnlockedAdventure] = true;
				EventFlagArray[EventFlags_BigUnlockedAdventure] = true;
				EventFlagArray[EventFlags_GammaUnlockedAdventure] = true;
				break;
			case 2:
				EventFlagArray[EventFlags_TailsUnlockedAdventure] = true;
				EventFlagArray[EventFlags_KnucklesAdventureComplete] = true;
				EventFlagArray[EventFlags_AmyUnlockedAdventure] = true;
				EventFlagArray[EventFlags_BigUnlockedAdventure] = true;
				EventFlagArray[EventFlags_GammaUnlockedAdventure] = true;
				break;
			case 3:
				EventFlagArray[EventFlags_TailsUnlockedAdventure] = true;
				EventFlagArray[EventFlags_KnucklesUnlockedAdventure] = true;
				EventFlagArray[EventFlags_AmyAdventureComplete] = true;
				EventFlagArray[EventFlags_BigUnlockedAdventure] = true;
				EventFlagArray[EventFlags_GammaUnlockedAdventure] = true;
				break;
			case 4:
				EventFlagArray[EventFlags_TailsUnlockedAdventure] = true;
				EventFlagArray[EventFlags_KnucklesUnlockedAdventure] = true;
				EventFlagArray[EventFlags_AmyUnlockedAdventure] = true;
				EventFlagArray[EventFlags_BigAdventureComplete] = true;
				EventFlagArray[EventFlags_GammaUnlockedAdventure] = true;
				break;
			case 5:
				EventFlagArray[EventFlags_TailsUnlockedAdventure] = true;
				EventFlagArray[EventFlags_KnucklesUnlockedAdventure] = true;
				EventFlagArray[EventFlags_AmyUnlockedAdventure] = true;
				EventFlagArray[EventFlags_BigUnlockedAdventure] = true;
				EventFlagArray[EventFlags_GammaAdventureComplete] = true;
				EventFlagArray[EventFlags_SuperSonicUnlockedAdventure] = true;
				break;
			case 6:
				EventFlagArray[EventFlags_SuperSonicAdventureComplete] = true;
				break;
			}

			GameMode = GameModes_StartCredits;
			GameState = 21;
			Credits_State = 1;
>>>>>>> 2abc2642de7a4355bb7c3faaa42106b4466908a6
			Load_SEGALOGO_E();
		}

		else
		{
			//set up final egg door rng
			RNGDoor = door[rand() % 5];

			if (RNGCharacters == true)
				do {
					CurrentCharacter = character[rand() % 6];
				} while (CurrentCharacter == CharacterCopy);
				

			if (RNGStages == true) {
				if (GameMode != 8)
				{
					if (Regular == true) //if the player activated the "banned regular stage option", check and ban the regular combination.
					{
<<<<<<< HEAD
					case Characters_Sonic:
						do {
							CurrentLevel = level[rand() % 18];
							CurrentAct = 0;
							MetalSonicFlag = metalsonicrng[rand() % 2];
							GameState = 17;
						} while (CurrentLevel == LevelCopy || (isValueInArray(bannedRegularSonic, CurrentLevel, 10)));
						break;
					case Characters_Tails:
						do {
							CurrentLevel = level[rand() % 18];
							CurrentAct = 0;
							MetalSonicFlag = 0;
							GameState = 17;
						} while (CurrentLevel == LevelCopy || (isValueInArray(bannedRegularTails, CurrentLevel, 5)));
						break;
					case Characters_Knuckles:
						do {
							CurrentLevel = level[rand() % 18];
							CurrentAct = 0;
							MetalSonicFlag = 0;
							GameState = 17;
						} while (CurrentLevel == LevelCopy || (isValueInArray(bannedRegularKnuckles, CurrentLevel, 1)));
						break;
					case Characters_Amy:
						do {
							CurrentLevel = level[rand() % 18];
							CurrentAct = 0;
							MetalSonicFlag = 0;
							GameState = 17;
						} while (CurrentLevel == LevelCopy || (isValueInArray(bannedRegularAmy, CurrentLevel, 3)));
						break;
					case Characters_Big:
=======
						switch (CurrentCharacter)
						{
						case Characters_Sonic:
							do {
								CurrentLevel = level[rand() % 18];
								MetalSonicFlag = metalsonicrng[rand() % 2];
								if (CurrentLevel == LevelIDs_TwinklePark || CurrentLevel == LevelIDs_Casinopolis)
								{
									CurrentAct = 1;
								}
								else
									if (CurrentLevel == LevelIDs_EmeraldCoast)
									{
										CurrentAct = 2;
									}
									else
									CurrentAct = 0;
								} while (CurrentLevel == LevelCopy || (CurrentLevel > 14 && LevelCopy > 14 || (isValueInArray(bannedRegularSonic, CurrentLevel, 9))));
							break;
						case Characters_Tails:
							do {
								CurrentAct = 0;
								MetalSonicFlag = 0;
								CurrentLevel = level[rand() % 18];
							} while (CurrentLevel == LevelCopy || (CurrentLevel > 14 && LevelCopy > 14 || (isValueInArray(bannedRegularTails, CurrentLevel, 5))));
							break;
						case Characters_Knuckles:
							do {
								CurrentAct = 0;
								MetalSonicFlag = 0;
								CurrentLevel = level[rand() % 18];
							} while (CurrentLevel == LevelCopy || (CurrentLevel > 14 && LevelCopy > 14 || (isValueInArray(bannedRegularKnuckles, CurrentLevel, 2))));
							break;
						case Characters_Amy:
							do {
								MetalSonicFlag = 0;
								CurrentLevel = level[rand() % 18];
								if (CurrentLevel == LevelIDs_HotShelter)
								{
									CurrentAct = 2;
								}
								else
									CurrentAct = 0;
							} while (CurrentLevel == LevelCopy || (CurrentLevel > 14 && LevelCopy > 14 || (isValueInArray(bannedRegularAmy, CurrentLevel, 1))));
							break;
						case Characters_Big:
							do {
								CurrentAct = 0;
								MetalSonicFlag = 0;
								CurrentLevel = level[rand() % 18];
							} while (CurrentLevel == LevelCopy || (CurrentLevel > 14 && LevelCopy > 14 || (isValueInArray(bannedRegularBig, CurrentLevel, 2))));
							break;
						case Characters_Gamma:
							do {
								CurrentAct = 0;
								MetalSonicFlag = 0;
								CurrentLevel = level[rand() % 18];
							} while (CurrentLevel == LevelCopy || (CurrentLevel > 14 && LevelCopy > 14 || (isValueInArray(bannedRegularGamma, CurrentLevel, 8))));
							break;
						}
					}
					else //if the player didn't activate the regular option
					{
						switch (CurrentCharacter)
						{
						case Characters_Sonic:
							MetalSonicFlag = metalsonicrng[rand() % 2];
							if (CurrentLevel == LevelIDs_TwinklePark || CurrentLevel == LevelIDs_Casinopolis)
							{
								CurrentAct = 1;
							}
							else
								if (CurrentLevel == LevelIDs_EmeraldCoast)
								{
									CurrentAct = 2;
								}
								else
									CurrentAct = 0;
							break;
						defaut:
							MetalSonicFlag = 0;
							break;
						}
>>>>>>> 2abc2642de7a4355bb7c3faaa42106b4466908a6
						do {
							CurrentLevel = level[rand() % 18];
							CurrentAct = 0;
<<<<<<< HEAD
							MetalSonicFlag = 0;
							GameState = 17;
						} while (CurrentLevel == LevelCopy || (isValueInArray(bannedRegularBig, CurrentLevel, 3)));
						break;
					case Characters_Gamma:
						do {
							CurrentLevel = level[rand() % 18];
							CurrentAct = 0;
							MetalSonicFlag = 0;
							GameState = 17;
						} while (CurrentLevel == LevelCopy || (isValueInArray(bannedRegularGamma, CurrentLevel, 8)));
						break;
=======
							CurrentLevel = level[rand() % 18];
						} while (CurrentLevel == LevelCopy || (CurrentLevel > 14 && LevelCopy > 14 || (CurrentCharacter == Characters_Gamma && isValueInArray(bannedLevelsGamma, CurrentLevel, 8) || (CurrentCharacter == Characters_Big && isValueInArray(bannedLevelsBig, CurrentLevel, 2)))));

>>>>>>> 2abc2642de7a4355bb7c3faaa42106b4466908a6
					}
				}
				else
				{
					if (RNGStages == false && Regular == true) //It's technically useless, but I need to make some test later.
					{
<<<<<<< HEAD
					case Characters_Sonic:
						MetalSonicFlag = metalsonicrng[rand() % 2];
						break;
					defaut:
						MetalSonicFlag = 0;
					}
					do {
						CurrentLevel = level[rand() % 18];
						GameState = 17;
						CurrentAct = 0;
					} while (CurrentLevel == LevelCopy || (CurrentCharacter == Characters_Gamma && isValueInArray(bannedLevelsGamma, CurrentLevel, 8) || (CurrentCharacter == Characters_Big && isValueInArray(bannedLevelsBig, CurrentLevel, 3))));
				}
			}
			else
			{
				if (RNGStages == false && Regular == true) 
				{ }
			}
			

			

		}
	}
}
=======
						return;
					}
				}
			}
		}
	}



	//cancel the reset position at 0 after quitting a stage.
	void CancelResetPosition() {
		NextLevel = LastLevel;
		NextAct = LastAct;
		GameMode = GameModes_Adventure_Field;
	}


	//Set Gamma's Timer to 6 min instead of 3.
	void SetGammaTimer(char param_1, char param_2) {
		param_1 = 6;
		param_2 = 0;
		TimeFrames = 0;
		TimeMinutes = param_1;
		TimeSeconds = param_2;
		return;
	}

	//Avoid getting the same character twice in a row and "fix" metal sonic emblems.
	void DisableTimeStuff() {
		TimeThing = 0;
		CharacterCopy = CurrentCharacter;
		MetalSonicFlag = 0;
		return;
	}

}


		
>>>>>>> 2abc2642de7a4355bb7c3faaa42106b4466908a6
