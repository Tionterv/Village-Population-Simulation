# Village-Population-Simulation


# Summary


A small simulation game of a village. The objective of the game is to climb through the ranks of  this population from [settlers] to [country]. The player will be given the choice based on each  day and season’s scenarios. Depending on the choices the player makes and its sequence, it  will impact the population, food, materials, and conflicts. Therefore, to level up through each  rank, you must increase and maintain the population number and food to material ratio  objectively.  


# Classes Description


1. Player​ - user choice[next day y/n], string input, menu [show, how much population by birth ] 
2. Village[multiple]​ - This class will encompass the characteristics of the village such 
 as the population, Well-being, happiness, death, 
3. Resources​: food storage[crop/livestock], minerals[wood, metal,] 
4. Events​ -  data member - bool neg/pos, natural disaster[climate change],  
Conflicts[raids,bandits, animals], Colonization?, Benefit [trade - off, scam], 
birth/fertility etc. sickness. 
5. Time​ - [4]Season[inheritance to natural disaster/resources], Day[random events],  
[next day] user choice? 
6. EventIO ​- Reads the events textfile. 
