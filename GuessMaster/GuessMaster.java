//Karina Moffat 20265729

package game;

import java.util.Date;
import java.util.Scanner;
import java.util.Random;

public class GuessMaster {
	private int numberOfCandidateEntities = 0;
	//instance variable to indicate number of candidate entities used in game, initialize to 0
	private Entity[] entities = new Entity[10];
	//instance variable to hold the values of these candidates
	
	public void addEntity(Entity entity)
			{
		if(!equals(entity))
		{
			entities[numberOfCandidateEntities] = entity;
			numberOfCandidateEntities++;
		}
		else
		{
			System.out.println("Entity already exists!");
		}
			}
	//a method to add entities to program. Will first ensure the entity
	//has not already been added, once this is confirmed the entity will be added

	public void playGame(Entity entity)
	{
		boolean incorrect = true;
		while(incorrect)
		{
			System.out.println("Enter birthday of " + entity.getName() + "using format month/day/year");
			Scanner person = new Scanner(System.in);
			String birthday = person.nextLine();
			
			if(birthday.equals("quit"))
			{
				System.exit(0);
				}
			Date inputDate = new Date(birthday);
			Date correct = entity.getBorn();
			
			if(inputDate.precedes(correct))
			{
				System.out.println("Incorrect. Try a later date.");
			}
			else if(inputDate.suceeds(correct))
			{
				System.out.println("Incorrect. Try an earlier date.");
			}
			else if(inputDate.equals(correct))
			{
				System.out.println("BINGO. You got it!!");
				System.out.println(entity.toString());
				incorrect=false;
			}
		}
	} //the method to play the guessing game using the given entity
	
	public void playGame(int entityInd)
	{
		if(entities[entityInd]==null)
		{
			playGame();
		}
		else
			playGame(entities[entityInd]);
	}//a method to get the entity that the guessing game will be played with

	public void playGame()
	{
		int indexValue = genRandomEntityInd();
		playGame(entities[indexValue]);
	}//a method to generate a random index value that will determine which
	//entity to use for the game
	
	int genRandomEntityInd()
	{
		Random randomValue = new Random();
		return randomValue.nextInt(numberOfCandidateEntities);
	}//a method to generate a random value to be used when no entity
	//is given to use for the game
	
	public static void main(String[] args) {
		System.out.println("Welcome to the birthday guessing game!");
		
		Entity trudeau = new Entity("Justin Trudeau", new Date("December", 25, 1971));
		Entity dion = new Entity("Celine Dione", new Date("March", 20, 1968));
		Entity usa = new Entity("United States", new Date("July", 4, 1776));
	
		GuessMaster gm = new GuessMaster();
		gm.addEntity(trudeau);
		gm.addEntity(dion);
		gm.addEntity(usa);
		
		gm.playGame();
		
	}
}


