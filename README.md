# Linear Feedback Shift Register (lfsr)
This project aims to create an ADT for a lfsr.

## Getting Started
To use the ADT one simply:
1. Creates a random 64 bit seed
2. Calls "new" and passes the seed to it to obtain a new lfsr instance
3. Calls "get_random" to get a random 64 bit value
4. Optionally calls "update_state" to update the internal lfsr state
4. Calls "delete" to delete the lfsr instance

## Quick note on the design
The entire register is 128 bits long. The
upper 64 bits is what is returned to the user and is considered the random number
The lower 64 bits is the state and is what the lfsr operates on. Should anyone
obtain the state the entire future and past of the lfsr is immediately known.
The same is true for the random number returned by the ADT. Once the output is
known the next output is known as well. Thus, this lfsr should not be used for
high security cryptographic needs.

## Requirements
A more general set of requirements will be listed to aid in the final touches
of this api.
