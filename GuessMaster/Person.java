//Karina Moffat 20265729

public class Person extends Entity{
    private String gender;

    public Person(String personName, Date birthDate, String gender, double difficulty){
        super (personName, birthDate, difficulty);
        this.gender = gender;
    } //method to initialize instance variables

    public Person (Person entity){
        super (entity.getName(), entity.getBorn(), entity.getDifficulty());
        this.gender = entity.getGender();
    }

    public Entity clone (Entity entity){
        Person newPerson = new Person ((Person) entity);
        return newPerson;
    }//method to copy data to newPerson variable

    public String getGender(){
        return gender;
    } //method to access value of gender

    public String to String(){
        return super.toString() +"Gender: " +gender +"\n";
    }//implement toString method from parent class

    public String entityType(){
        return "This entity is a Person!";
    }//method to print given phrase to console
}