/** \file state_machine.c
 *  \brief State machine example source file.
 *
 *  This is the main source file of a fictitious firmware implementation as
 *  a state machine (automaton).
 *  \author Fernando C. Guimaraes
 *  \date 2020-12-11
 */
#include <dev_helper.h>
#include <state_machine.h>

/********************* Declaration of function headers ****************************/

// Private LED_OFF state function declaration.
static int st_1(STATE_FUNCTIONS_ARGS);

// Private LED_ON state function declaration.
static int st_2(STATE_FUNCTIONS_ARGS);

// Private LED_PWM_SETUP (internal) state function declaration.
static int st_3(STATE_FUNCTIONS_ARGS);

// Private LED_PWM_RUN (internal) state function declaration.
static int st_4(STATE_FUNCTIONS_ARGS);

// Private LED_PWM_RUN (internal) state function declaration.
static int st_5(STATE_FUNCTIONS_ARGS);

// Private LED_PWM_RUN (internal) state function declaration.
static int st_6(STATE_FUNCTIONS_ARGS);

// Private LED_PWM_RUN (internal) state function declaration.
static int st_7(STATE_FUNCTIONS_ARGS);

// Private LED_PWM_RUN (internal) state function declaration.
static int st_8(STATE_FUNCTIONS_ARGS);

// Private LED_PWM_RUN (internal) state function declaration.
static int st_9(STATE_FUNCTIONS_ARGS);

// Declaration of a private 'get' function used to return the last event.
static event_id sm_private_get_event(void);

// Declaration of a private 'set' function used by internal states to allow
// external events recognition.
static void sm_private_set_event(event_id event);

/********************* Global variables *******************************************/

static event_id _event = EV_NONE; // current event
static state_id _state = ST_1; // initial state (it could be declared inside sm_run)

// Function pointers array
// ----> Change this array accordingly to your automaton model
const static state_handler state_handler_container[NUMBER_ST] =
{
   [ST_1] = {ST_1, st_1},
   [ST_2] = {ST_2, st_2},
   [ST_3] = {ST_3, st_3},
   [ST_4] = {ST_4, st_4},
   [ST_5] = {ST_5, st_5},
   [ST_6] = {ST_6, st_6},
   [ST_7] = {ST_7, st_7},
   [ST_8] = {ST_8, st_8},
   [ST_9] = {ST_9, st_9}
};


/********************* Implementation of functions *************************************/

/********************* State functions *************************************************/

// ----> Implement your own state functions

// Private LED_OFF state function implementation.
static int st_1(STATE_FUNCTIONS_ARGS)
{
   PDEBUGY("sm_1 execution - Sistema Desligado\n");

   // Configure GPIO and set its output to 0.
   // Return -1 if something goes wrong.

   return 0;
}


// Private LED_ON state function implementation.
static int st_2(STATE_FUNCTIONS_ARGS)
{
   PDEBUGY("sm_2 execution - Sistema Ligado\n");

   // Configure GPIO and set its output to 1.
   // Return -1 if something goes wrong.

   return 0;
}

// Private LED_PWM_SETUP (internal) state function implementation.
static int st_3(STATE_FUNCTIONS_ARGS)
{
   PDEBUGY("st_3 execution - Motor Ligado - Contador = 0\n");

   // Get PWM period and duty cycle from ext_data buffer
   // Configure GPIO, set the initial values of variables (and put them into in_data buffer), etc.
   // Return -1 if something goes wrong.

   // 'lock' the SM in order to execute the next internal state (ST_LED_PWM_RUN) independently of
   // new incoming events from 'outside' (which are all discarded).

   return 0;
}

// Private LED_PWM_RUN (internal) state function implementation.
static int st_4(STATE_FUNCTIONS_ARGS)
{
   PDEBUGY("sm_4 execution - Sensor Ativado - Contador = 1\n");

   // Count the number of delay intervals and toggle the GPIO accordingly (also setting the counter to 0).
   // The value of the delays counter is shared across multiple executions by saving it in_data buffer.
   // Return -1 if something goes wrong.

   // 'unlock' the SM. If no external event occurs, it keeps executing this state, in order to periodically
   // toggle the GPIO.

   return 0;
}

static int st_5(STATE_FUNCTIONS_ARGS)
{
    PDEBUGY("sm_5 execution - Sensor Ativado - Contador = 2\n");

    // Configure GPIO and set its output to 0.
    // Return -1 if something goes wrong.

    return 0;
}

static int st_6(STATE_FUNCTIONS_ARGS)
{
    PDEBUGY("sm_6 execution - Sensor Ativado - Contador = 3\n");

    // Configure GPIO and set its output to 0.
    // Return -1 if something goes wrong.

    return 0;
}

static int st_7(STATE_FUNCTIONS_ARGS)
{
    PDEBUGY("sm_7 execution - Sensor Ativado - Contador = 4\n");

    // Configure GPIO and set its output to 0.
    // Return -1 if something goes wrong.

    return 0;
}

static int st_8(STATE_FUNCTIONS_ARGS)
{
    PDEBUGY("sm_8 execution - Sensor Ativado - Contador = 5 - Sistema Finalizado\n");

    // Configure GPIO and set its output to 0.
    // Return -1 if something goes wrong.

    return 0;
}

static int st_9(STATE_FUNCTIONS_ARGS)
{
    PDEBUGY("sm_9 execution - Estado de Emergência\n");

    // Configure GPIO and set its output to 0.
    // Return -1 if something goes wrong.

    return 0;
}

/********************* 'get' and 'set' functions *********************************************/

// sm_private_get_event implementation.
static event_id sm_private_get_event(void)
{
   event_id new_event;

   PDEBUG("sm_private_get_event execution\n");

   // Read the current event and reset it.
   new_event = _event;
   _event = EV_NONE;

   return new_event;
}

// sm_private_set_event implementation.
static void sm_private_set_event(event_id event)
{
   PDEBUG("sm_private_set_event execution\n");

   // The value of event is not checked in this private 'set' function. The SM programmers should know what
   // they're doing.
   _event = event;
}

// sm_set_event implementation.
int sm_set_event(event_id event)
{
   int ret = -1; // return -1 if event is ignored.

   PDEBUG("sm_set_event_event execution\n");

   // First check if event value is valid. Obs.: EV_NONE is not recognized because it would be useless.
   if((event > 0) && (event < NUMBER_EV)) {
      // 1st condition: if current event is internal and 'locking', ignore the external event.
      // 2nd condition: block an external attempt to 'lock' the SM.
     // if((_event != EV_INTERNAL_LOCK) && (event != EV_INTERNAL_LOCK)) {
         _event = event;
         ret = 0;
     // }
   }
   // Of course, all conditions can be put in one single 'if'.

   return ret;
}

/********************* Public SM functions *********************************************/

// sm_setup implementation.
void sm_setup(void)
{
   // Nothing to do in this fictitious firmware, just print a msg.
   PDEBUG("sm_setup execution\n");
}

// sm_run implementation
int sm_run(void)
{
   int ret = 0;
   event_id event = EV_NONE;
   state_id next_state = _state; // Current state

   // Dynamic memory allocation could be used (in setup function), but for microcontrollers with
   // bare-metal, monolithic firmware, this is usually better.
   static int16_t ex_data[OUT_BUFFER_SIZE];
   static int16_t in_data[IN_BUFFER_SIZE];

   // Transition function array: given a state and an event, it returns the next state.
   // Be careful! The events ordering defined in 'typedef enum event_id' must be obeyed.
   // ----> Change this transition function accordingly to your automaton model!
   const static state_id f[NUMBER_ST][NUMBER_EV] =
   {
      [ST_1]       = {ST_NULL, ST_2, ST_NULL, ST_NULL, ST_NULL, ST_NULL,ST_NULL,ST_NULL},
      [ST_2]       = {ST_NULL, ST_NULL, ST_3, ST_NULL, ST_NULL, ST_9,ST_1,ST_NULL},
      [ST_3]       = {ST_NULL, ST_NULL, ST_NULL, ST_4, ST_NULL, ST_9,ST_1,ST_NULL},
      [ST_4]       = {ST_NULL, ST_NULL, ST_NULL, ST_5, ST_NULL, ST_9,ST_1,ST_NULL},
      [ST_5]       = {ST_NULL, ST_NULL, ST_NULL, ST_6, ST_NULL, ST_9,ST_1,ST_NULL},
      [ST_6]       = {ST_NULL, ST_NULL, ST_NULL, ST_7, ST_NULL, ST_9,ST_1,ST_NULL},
      [ST_7]       = {ST_NULL, ST_NULL, ST_NULL, ST_8, ST_NULL, ST_9,ST_1,ST_NULL},
      [ST_8]       = {ST_NULL, ST_NULL, ST_NULL, ST_NULL, ST_3, ST_9,ST_1,ST_2},
      [ST_9]       = {ST_NULL, ST_NULL, ST_NULL, ST_NULL, ST_NULL, ST_NULL,ST_1,ST_NULL}
   };

   PDEBUG("sm_run execution\n");

   // At each cycle, get the new event, which was set by 'external world' or by a SM internal state
   event = sm_private_get_event();

   // In order to save power, do something if there is a new event only.
   if(event != EV_NONE) {
      // Get the next state to be executed
      next_state = f[_state][event];

      if(next_state != ST_NULL) {
         // Update the current state variable
         _state = next_state;

         // Execute next state function, return 0 if everything went OK or -1 otherwise
         ret = state_handler_container[_state].state_exe(ex_data, in_data);
      }
      else {
         // If the new event is not recognized in current state, f returns a 'NULL' state, and the function
         // returns an error code.
         return -1;
      }
   }

   return ret;
}

// sm_close implementation.
void sm_close(void)
{
   // Nothing to do in this fictitious firmware, just print a msg.
   PDEBUG("sm_close execution\n");
}



