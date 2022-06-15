import javax.crypto.Cipher;
import javax.crypto.SecretKey;
import java.io.FileOutputStream;
import java.nio.ByteBuffer;
import java.security.SecureRandom;
import java.util.ArrayList;
/**
 * A puzzle creator class
 * @author Stefani Dimitrova
 */
public class PuzzleCreator {

    ArrayList<Puzzle> puzzles = new ArrayList<Puzzle>();

    /**
     * A puzzles constructor
     */
    public PuzzleCreator() {

    }

    /**
     * A method to create 4096 puzzles and
     * stores them in an ArrayList
     * @return the ArrayList of puzzles
     */
    public ArrayList<Puzzle> createPuzzles() {

        int i = 0;
        try {
            for (i = 1; i <= 4096; i++) {

                byte[] key = createRandomKey();

                this.puzzles.add(new Puzzle(i, CryptoLib.createKey(key)));
            }
        } catch (Exception e) {
            i--;
        }

        return puzzles;
    }

    /**
     * A method to create a random key and stores it as bytes
     * with the last 48 bits being zeroes
     * @return the byte array
     */
    public byte[] createRandomKey() {

        byte[] firstBytes = new byte[2];
        SecureRandom random = new SecureRandom();
        random.nextBytes(firstBytes);
        byte[] lastBytes = new byte[6];

        byte[] randomKey = ByteBuffer.allocate(firstBytes.length + lastBytes.length).put(firstBytes).put(lastBytes).array();

        return randomKey;
    }

    /**
     * Encrypting the puzzle using DES
     * @param key a byte array representing the key
     * @param puzzle a Puzzle object
     * @return byte array
     */
    public byte[] encryptPuzzle(byte[] key, Puzzle puzzle) {
        byte[] puzzleAsBytes = puzzle.getPuzzleAsBytes();

        try {
            Cipher cipher = Cipher.getInstance("DES");
            SecretKey myKey = CryptoLib.createKey(key);
            cipher.init(Cipher.ENCRYPT_MODE, myKey);

            byte[] encryptedPuzzle = cipher.doFinal(puzzleAsBytes);
            return encryptedPuzzle;
        } catch (Exception e) {
            System.out.println("Error");
            return null;
        }


    }

    /**
     * Encrypting all 4096 puzzles and
     * writes them to a binary file
     * @param filename the file to be written in
     */
    public void encryptPuzzlesToFile(String filename) {

        try {
            FileOutputStream stream = new FileOutputStream(filename);
            for(int i = 0; i < 4096; i++){
                stream.write(encryptPuzzle(puzzles.get(i).getKey().getEncoded(), puzzles.get(i)));
            }
        } catch(Exception e) {
            System.out.println("Error");
        }
    }

    /**
     * Finding a key using the puzzle number
     * @param puzzle_num used to find the puzzle
     * @return the key
     */
    public SecretKey findKey(int puzzle_num) {
        for(int i = 0; i < 4096; i++){
            if(puzzles.get(i).getPuzzleNumber() == puzzle_num){
                return puzzles.get(i).getKey();
            }
        }
        return null;
    }
}