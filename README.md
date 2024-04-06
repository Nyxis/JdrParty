## Table of Contents
1. [Introduction](#introduction)
2. [Random Outcome Class](#random-outcome-class)
3. [Behavior for Random Values](#behavior-for-random-values)
4. [Material Classes](#material-classes)
5. [GameMaster Class](#gamemaster-class)
6. [Logging Utility](#logging-utility)
7. [Java GUI Application](#java-gui-application)
8. [Integration with C++ Binary](#integration-with-c-binary)

## Introduction
In order to animate a tabletop role-playing game (RPG) session, a Game Master (GM) brings along a set of equipment to manage the random outcomes resulting from player choices.

At each action, the GM will randomly choose one of the items in their possession to draw the value. This value can be a success, a failure, a critical success, or a fumble. Depending on the action, the success rate, critical rate, and fumble rate will vary.

## Random Outcome Class
1. **Objective:** Model a class representing a random outcome.
   - This class should encapsulate the type of outcome (success, failure, critical success, fumble).

## Behavior for Random Values
2. **Objective:** Model behavior corresponding to the drawing of these random values.
   - Implement methods to generate random outcomes based on given success, critical, and fumble rates.

## Material Classes
3. **Objective:** Model classes for the three types of equipment available to the GM.
   - Dice: Can be created with a list of faces or a number of faces. It generates a value corresponding to one of its faces during the draw.
   - Coin: Can only return two values but depends on a number of tosses. The generation returns 1 only if x tosses are 1.
   - Deck of cards: Depends on a number of colors and values. Its generation method returns a value between 1 and number of colors * number of values after two draws: the first on the color, the second on the value.

## GameMaster Class
4. **Objective:** Create a GameMaster class.
   - A GameMaster has a significant number of various types of dice, two decks of cards (one with three colors and 18 values, the other with four colors and 13 values), and two coins.
   - The GameMaster can perform draws using the `pleaseGiveMeACrit` method, with the three rates (success, critical, fumble) expressed in percentage. The GameMaster selects one of the instances of Dice/Deck and Coin at random and returns a constant corresponding to the type of result.

## Logging Utility
5. **Objective:** Implement a logging utility class and methods to write messages to the command line from your classes, instead of using cout directly. The implementation should allow choosing the appropriate behavior.
   - Implement a function `log(message)` in this class.
   - Ensure that this class is usable in your objects without passing it as a parameter to the constructor.

## Java GUI Application
6. **Objective:** Create a new Java project with a graphical user interface (GUI) using JavaFX to display four buttons corresponding to four actions. Upon clicking one of the buttons, the corresponding rates should be displayed in the standard output.

## Integration with C++ Binary
7. **Objective:** Upon clicking a button, instead of displaying the scores, use Java's ProcessBuilder to generate a call to the compiled C++ binary, passing the critical/failure/fumble rates as arguments. You will need to modify your main file to read these arguments and return the result as a return code. The Java program should read the return code to color the button:
   - Green if the action is a success.
   - Red if the action is a failure.
   - Black if the action is a fumble.
   - Ensure the use of SOLID principles and at least one design pattern in these implementations.
