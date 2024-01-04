//Karina Moffat 20265729

package game;

import java.util.jar.Attributes.Name;

abstract class Entity {
	private final String name;
	private final Date born;
	private final double difficulty; //keeps difficulty of guessing entity and is used to calculate number of tickets recieved by user
	//initializing instance variables
	
	public Entity(String name, Date born, double difficulty)
	{
		this.name = name;
		this.born = new Date(born);
		this.difficulty = difficulty; //avoids privacy leak
	}
	//constructor method 
	
	public Entity(Entity copy)
	{
		this.name = entity.name
	}
	//copy method
	
	public boolean equals(Entity entity)
	{
		if(entity == null)
		{
			return false;
		}
		else if (this.born.equals(entity.born) && this.name.equals(entity.name))
{
	return true; //if values are equal, method returns true
}

	return false; //if values are not equal, method returns false
	}
//method to determine if the two values are equal or not

	public Entity(Entity entity) {
		this.name = entity.name;
		this.born = new Date (entity.born);
		this.difficulty = entity.getDifficulty(); //avoids privacy leak
	}
	
	public int getAwardedTicketNumber() {
		Integer numberTickets = (int)(difficulty*100); //cast value to be an integer, can't have decimal of a ticket
		return numberTickets;
	}
	//method returns number of tickets if user correctly guesses birth date
	
	public String toString()
	{
		String data = (this.name + "born on" + born.toString());
		
		return data;
	}//method to return content of entity as a string
	
	abstract String entityType();
	//returns short description of entity type
	
	abstract Entity clone(); 
	
	public void welcomeMessage() {
		System.out.println("Welcome! Let's start the game! This entity is a " + entityType());
	}
	//generates proper welcome message
	
	public void cloningMessage() {
		System.out.println("Congratulations! The detailed information of the entity you guessed is:" + toString());
	}
	//provides information of entity being guessed
	public Entity(String name) {
		this.name = name;
	}
	public String getName() {
		return name;
	}
	public Date getBorn() {
		return new Date(born);
	}
	public void setBorn(Date born) {
		this.born=born;
	}
	public double getDifficulty() {
		return difficulty;
	}
	//setting methods to have no privacy leaks
}
