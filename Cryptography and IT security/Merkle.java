import javax.crypto.Cipher;
import javax.crypto.SecretKey;
import java.util.ArrayList;
import java.util.Random;


public class Merkle {
    /**
     * A main class
     * @author Stefani Dimitrova
     */
    public static void main(String[] args) {

        //1 creating an encrypted puzzle file, representing Alice's puzzles
        PuzzleCreator puzzle = new PuzzleCreator();
        puzzle.createPuzzles();
        puzzle.encryptPuzzlesToFile("puzzles.bin");

        //2 cracking a random puzzle
        Random r = new Random();
        int randomInt = r.nextInt(4096);

        PuzzleCracker puzzleCracker = new PuzzleCracker("puzzles.bin");
        Puzzle cracked = puzzleCracker.crack(randomInt + 1);

        //3 finding Alice's puzzle with the same puzzle number as Bobs puzzle
        int crackedPuzzleNum = cracked.getPuzzleNumber();
        SecretKey key = puzzle.findKey(crackedPuzzleNum);

        //4 encrypting the message using Alice's puzzle key
        try{
            String plainText = "Testing Merkles Puzzles!";
            byte[] plainTextByte = plainText.getBytes();

            Cipher cipher = Cipher.getInstance("DES");
            cipher.init(Cipher.ENCRYPT_MODE, key);
            byte[] bytesEncryption = cipher.doFinal(plainTextByte);

            puzzleCracker.decryptMessage(bytesEncryption);

        }catch (Exception e){

        }


    }

}
