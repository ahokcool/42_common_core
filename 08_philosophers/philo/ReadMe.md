## philosophers
this project is a version of the dinning philosopher problem <br>
[->Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
<br>

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/7/7b/An_illustration_of_the_dining_philosophers_problem.png/800px-An_illustration_of_the_dining_philosophers_problem.png" width="300" />

| Commont Problems  | My Solution |
| ------------- | ------------- |
| independent philos                | -> using threads  |
| race conditions                   | -> using pthread_mutex  |
| deadlocks                         | [-> resource hierarchy solution]([https://www.mathworks.com/help/simevents/ug/dining-philosophers-problem.html](https://medium.com/science-journal/the-dining-philosophers-problem-fded861c37ed)https://medium.com/science-journal/the-dining-philosophers-problem-fded861c37ed)  |
| the starvation                    | -> wait for a lap time |

### the starvation solution
Every philo can see how many other philos are sitting at the table. Always half of the philos (result rounded down) can eat at the same time (exception: there is only one philo). Since in this variant all philos always eat the same amount of time, it can be calculated how long it takes until all have started to eat once. If each philo now waits until at least this time has passed before he eats again, nobody starves anymore. HOORAY! 
