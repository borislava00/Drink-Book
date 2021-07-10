# DrinkBook
Small OOP project for university.

Examples for inheritance, polymorphism, hierarchical structure and encapsulation can be found in the project.

## Project explanation
     - Music preferences
     - Folk - doesnt like house music
     - House - doesnt like rock music
     - Rock - doesnt like folk music  
     - No preferences - likes all types of music
  
## Club rules for users
     - User likes club type
     - The club is not full
     - User has enought money to pay his drinks
     - User is not underaged (underaged users can enter only folk clubs and must pay 20$ fee to the guard)

| Classes | Caracteristics                        | Base class|
| ------- |:--------------------------------------|:---------:|
|User	|name,years,money,music,whiskies,vodka  |	no     |  
|ClubsBase|size, whisky price ,vodka price	     |no         |
|FolkClub	|performer,size,whisky price,vodka price|ClubsBase  |
|HouseClub|whisky price,vodka price, djs	     |ClubBase   |
|RockClub	|size,whisky price,vodka price	     |ClubBase   |
|Clubs    |collection of different clubs	     |no         |
