// from: https://www.youtube.com/watch?v=g1N_ttH0FQE

// we can typedef a function pointer for a function with specific arguments and return type:
// (the arguments do not need names)
typedef uint32_t (*command_ptr)(uint32_t);

// then define some functions with the same arguments and return type:
uint32_t setSpeed(uint32_t speed);
{
	outputSpeed = speed;
}
uint32_t drawLine(uint32_t length);
{
	drawLine(length);
}

// then set a metafunction to call the appropriate function:
uint32_t doCommand(command_ptr command, uint32_t value)
{
	return command(value);
}

// then call the metafunction with appropriate arguments
uint32_t result = doCommand(setSpeed, commandValue);

// and most importantly create a function map:
// start with a typdef'd function pointer
typedef uint32_t (*command_function)(uint32_t);

// then creat a typedef'd struct for the map containing a name string and a function to call
typedef struct
{
	char*            commandName;
	command_function commandFunction;
}
command_type;

// then create a filled (const) array of these structs
const command_type commandLibrary[]
{
	{"SET_SPEED", setSpeed},
	{"DRAW_LINE", drawLine},
	{"", NULL},
};

// then a function to map the name to the function:
// (takes a string as an argument and returns a function pointer)
#define NUM_COMMANDS 3 // needs to relate to the commandLibrary
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

// then a function to call the appropriate function
#define INVALID_VALUE 0xFFFFFFFF
uint8_t doCommand(char* buffer) // the buffer contains command name and value in ascii
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
