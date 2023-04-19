# Philosophers

42 Project about solving the Dining Philosophers problem - learning about resource sharing, deadlock and multi threading in C.

>One or more philosophers sit at a round table. There is a large bowl of spaghetti in the middle of the table. The philosophers alternatively **eat**, **think**, or **sleep**. There are also forks on the table. There are **as many forks as philosophers**. A philosopher uses **two forks to eat**. When a philosopher has finished eating, they put their forks back on the table and start sleeping. Once awake, they start thinking again. The simulation stops when a philosopher dies of starvation.

## **About:**
**Mandatory part:**
- Your(s) program(s) should take the following arguments:
	- `number_of_philosophers` - The number of philosophers and also the number of forks.
	- `time_to_die` - Time *(in milliseconds)* it takes a philosopher to die since their last meal.
	- `time_to_eat` - Time *(in milliseconds)* it takes a philosopher to eat, during which they hold two forks.
	- `time_to_sleep` - Time *(in milliseconds)* a philosopher spends sleeping.
	- `number_of_times_each_philosopher_must_eat` - *Optional argument*, simulation stops after each philosopher ate this argument of times. If not specified, it stops when a philosopher dies.
- Each philosopher has a number ranging from `1` to `number_of_philosophers`.
- Philosopher number `1` sits next to philosopher number `number_of_philosophers`.
- Any other philosopher number `N` sits between philosopher number `N - 1` and philosopher number `N + 1`.
- Your program must not have any data races.
- Each philosopher should be a thread.
- Each philosopher has a fork on their left side and a fork on their right side. If there is only one philosopher, there should be only one fork on the table.
- To prevent philosophers from duplicating forks, you should protect the forks state with a mutex for each of them

**About the logs:**
- Any state change of a philosopher must be formatted as follows:
	- `timestamp_in_ms X has taken a fork`
	- `timestamp_in_ms X is eating`
	- `timestamp_in_ms X is sleeping`
	- `timestamp_in_ms X is thinking`
	- `timestamp_in_ms X died` 
- A displayed state message should not be mixed up with another message.
- A message announcing a philosopher died should be displayed no more than 10 ms after the actual death of the philosopher.

**Bonus part:**
- The program of the bonus part takes the same arguments as the mandatory program.
- All the forks are put in the middle of the table.
- They have no states in memory but the number of available forks is represented by a semaphore.
- Each philosopher should be a process. But the main process should not be a philosopher.
