// from: https://www.youtube.com/watch?v=g1N_ttH0FQE
// right left rule:
// look right then left then go outside parentheses and do the same again

so (*foo) foo is a pointer

// (*foo)(int); foo is a pointer to a function that takes an int
// int *(*foo)(int); foo is a pointer to a function that takes an int and returns a pointer to an int


// we can typedef the function pointer for a function with specific arguments and returns:
typedef uint32_t (*command_ptr)(uint32_t);
// then define some functions with the same arguments and return type:
uint32_t setSpeed(uint32_t speed);
{
	outputSpeed = speed;
}
uint32_t drawLine(uint32_t length);
{
	drawALine(length);
}

// then set a metafunction to call the appropriate function:
int doCommand(command_ptr command, uint32_t commandValue)
{
	return command(commandValue);
}

// then call the metafunction with appropriate arguments

uint32_t result = doCommand(setSpeed, commandValue);

// then set a metafunction


//
//
// SIMPLEST FORM

uint32_t setSpeed(uint32_t commandValue;
{
	outputSpeed = commandValue;
	return 0;
}

uint32_t drawLine(uint32_t commandValue);
{
	drawALine(commandValue);
	return 0;
}

uint32_t (*command)(uint32_t) = setSpeed; // needs to be used in full every call...

command(currentCommandValue); // calls setSpeed 

//with typedef:

typedef uint32_t (*command_function)(uint32_t); // use once

command_function command = drawLine; 

command(currentCommandValue); // calls drawLine

// we can also pass the funtion pointer to another function:

void doCommand(command_function function, uint32_t value)
{
	function(value);
}

// and most importantly create a function map:


typedef uint32_t (*command_function)(uint32_t);

typedef struct
{
	char*            commandName;
	command_function commandFunction;
}   command_type;

#define NUM_COMMANDS 2
#define INVALID_VALUE 0xFFFFFFFF
const command_type commandLibrary[]
{
	{"SET_SPEED", setSpeed},
	{"DRAW_LINE", drawLine},
	{"", NULL},
};

command_function getCommand(char *s)
{
	for(int i=0; i < NUM_COMMANDS; i++)
	{
		if match(s, commandLibrary[i].commandName) // need to write match()
		{
			return commandLibrary[i].commandFunction;
		}
	}
	return NULL;
}

uint8_t doCommand(char* buffer)
{
	command_function command = getCommand(buffer);
	uint32_t value = getValue(buffer); // need to write getValue()
	if((command == NULL) || value = INVALID_VALUE)
	{
		return 1;
	}
	command(value);
	return 0;
}
