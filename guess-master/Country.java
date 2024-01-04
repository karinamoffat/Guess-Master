//Karina Moffat 20265729

public class Country extends Entity{
    private String capital;

    public Country (String counrtyName, Date birthDate, String capitalCity, double difficulty){
        super (countryName, birthDate, difficulty);
        this.capital = capitalCity;
    } //initialize instance variables in Country class and instances in its parent class
    public Country (Country entity){
        super (entity.getName(), entity.getBorn(), entity.getDifficulty());
        this.capital = entity.getCapital();
    }

    public Entity clone (Entity entity){
        Country newCountry = new Country ((Country)entity);
        return newCountry;
    } //method to set a value to the new country that has been created

    public String getCapital(){
        return capital;
    } //constructor method to retreive that value of the capital city

    public String toString(){
        return super.toString() +"Capital: " +capital +"\n"";
    } //use toString to invoke the method from parent class

    public String entityType(){
        return "This entity is a country!";
    } //method to print given phrase to console
}