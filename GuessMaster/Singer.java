//Karina Moffat 20265729

public class Singer extends Person{
    private String debutAlbum;
    private Date debutAlbumReleaseDate;

    public Singer (String name, Date birthDate, String gender, String debutAlbum, Date debutAlbumReleaseDate, double difficulty){
        super (name, birthDate, gender, difficulty);
        this.debutAlbum = debutAlbum;
        this.debutAlbumReleaseDate = new Date(debutAlbumReleaseDate);
    }//initializing new variables for Singer

    public Singer (Singer entity){
        super (entity.getName(), entity.getBorn(), ((Person)entity.getGender(), entity.getDifficulty());
        this.debutAlbum = entity.getDebutAlbum();
        this.debutAlbumReleaseDate = entity.getDebutAlbumDate();
    }

    public Singer clone (Singer entity) {
        Singer newSinger = new Singer (entity);
        return newSinger;
    }

    public String getDebutAlbum() {
        return debutAlbum;
    }

    public Date getDebutAlbumDate(){
        return debutAlbumReleaseDate;
    }

    public String toString(){
        return super.toString() + "Debut Album: "debutAlbum+ "\n" + "Release Date: " + debutAlbumReleaseDate.toString() + "\n";
    }//implement toString method from parent class

    public String entityType() {
        return "This entity is a Singer!";
    }
}