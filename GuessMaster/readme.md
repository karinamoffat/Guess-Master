# GuessMaster
## Object
To get as many tickets as possible. This is done by correctly guessing the birth date of given entity. The number of tickets awarded for a correct answer is the difficulty factor multiplied by 100. 
## How it works
- User is greated with a welcome message: "Welcome! Let's start the game! This entity is a XXX", where XXX is an entity type
- Read user answer from console. If **incorrect** and guess is **too early**, print "Incorrect. Try a later date." If **incorrect** and guess is **too late**, print "Incorrect. Try an earlier date." If **correct**, print "BINGO. You got it!"
- User will win tickets if guess is correct. For every round of guess, if user is correct print the number of tickets received in this round, plus total number of tickets recieved so far since start of the game.
- Number of tickets won depends on the difficulty level of the entity that was guessed. A 'difficulty' level is given to each entity, ranging from 0 to 1.
- For each round of correct guess, a closing message is printed: "Congratulations! The detailed information of the entity you guessed is: XXX", where XXX is the detailed information of the eneity being guessed.
