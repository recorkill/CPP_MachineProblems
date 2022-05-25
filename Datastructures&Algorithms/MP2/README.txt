For this assignment, a C++ program was created to simulate the waiting line of customers at a restaurant. The rules to this scenario are that:
1.	A customer will leave for the restaurant and take between one and four minutes to arrive (and will enter the line upon arrival).
2.	Once a customer arrives at the restaurant, the next customer will leave for the restaurant (also taking between one and four minutes to arrive, only one customer will be travelling towards the restaurant at a time).
3.	A customer will be served every one to four minutes, and this customer will be the one at the front of the line (the front of the queue).
4.	Once the customer at the front of the line is served, they will be removed from the line and the customer behind them in line will be the new front of the line (to be served in one to four minutes as well).
The simulation was run for 120 minutes; each minute was printed to the user, along with the events that occurred in that minute (arrivals, departures, etc.). 
Machine Problem Questions
a. What is the maximum number of customers in the queue at any time?
The scenario that would lead to the most possible customers in line for this simulation would be if every customer happened to arrive in the shortest possible time (1 minute) every time, and a customer was served in the longest possible time (4 minutes) every time. In this simulation of 120 minutes, 120 customers would arrive in this time (at a rate of 1 per minute). In this time, only 29 customers would be served (at a rate of 4 minutes per customer). This would lead to a line of 91 customers as the simulation concluded. The simulator was re-run to verify this with static values of 4 and 1 for service time and arrival time, respectively. 
b. What is the longest wait any one customer experiences?
Drawing back to the previous answer, in the “worst case” scenario of 1-minute arrival times and 4-minute service times, the line would stand at 91 customers at the conclusion of the simulation. The 91st customer in this line would be waiting for 364 minutes to be served.
c. What happens if the arrival interval is changed from 1-4 minutes to 1-3 minutes?
If the arrival time and service times were no longer in the same range, and the arrival time became, on average, shorter than the service time, the line would continually increase in length as time went on. As time approaches infinity, the length of the line would also approach infinity.
