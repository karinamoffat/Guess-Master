//Karina Moffat 20265729

public class Politician extends Person{
    private String party;

    public Politician (String name, Date birthDate, String gender, String party, double difficulty){
        super(name, birthDate, gender, difficulty);
        this.party = party;
    }//initialize new variables for politician

    public Politician (Politician entity){
        super (entity.getName(), entity.getBorn(), ((Person)entity).getGender(), entity.getDifficulty());
        this.party = entity.getParty();
    }

    public Politician clone(Politician entity) {
        Politician newPolitician = new Politician(entity);
        return newPolitician;
    }

    public String getParty(){
        return party;
    }

    public String toString() {
        return super.toString() + "Party: " +party +"\n";
    } //implement toString method from parent class

    public String entityType(){
        return "This entity is a Politician!";
    }
}