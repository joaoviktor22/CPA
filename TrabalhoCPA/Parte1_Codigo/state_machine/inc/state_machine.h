/** \file state_machine.h
 *  \brief State machine example header file.
 *
 *  This is the main source file of a fictitious firmware implementation as
 *  a state machine (automaton).
 *  \author Fernando C. Guimaraes
 *  \date 2020-12-11
 */

#ifndef STATE_MACHINE_H_
#define STATE_MACHINE_H_

#include <stdint.h>

#define STATE_FUNCTIONS_ARGS      int16_t *ex_data, int16_t *in_data
#define IN_BUFFER_SIZE            1
#define OUT_BUFFER_SIZE           2

typedef enum
{
   ST_NULL = 0,
   ST_1,
   ST_2,
   ST_3,
   ST_4,
   ST_5,
   ST_6,
   ST_7,
   ST_8,
   ST_9,
   NUMBER_ST
} state_id;

typedef enum
{
   EV_NONE = 0,
   EV_A,
   EV_B,
   EV_C,
   EV_D,
   EV_E,
   EV_F,
   EV_G,
   NUMBER_EV
} event_id;

typedef struct
{
   state_id st_id;
   int (*state_exe)(STATE_FUNCTIONS_ARGS);
} state_handler;

// Public function used to tell the SM what the new incoming event is. It can be called by an interrupt
// function or a polling one responsible for inputs reading. External interrupts are triggered by
// rise or falling edges of GPIOs and other peripherals. The polling method only reads the GPIOs states
// at the reading moment.
int sm_set_event(event_id event);

// Public function used to setup whatever the SM needs (peripherals registers, memory allocation, etc.)
void sm_setup(void);

// Public function which executes the current state function.
int sm_run(void);

// Public function used to turn things off, to deallocate memory, etc.
void sm_close(void);


#endif /* STATE_MACHINE_H_ */
