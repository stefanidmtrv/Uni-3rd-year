import javax.crypto.SecretKey;
import java.nio.ByteBuffer;

/**
 * A puzzle class
 * @author Stefani Dimitrova
 */
public class Puzzle {

    public int puzzle_num;
    private SecretKey secretKey;

    /**
     * Create a puzzle instance
     * @param puzzle_num the puzzle number
     * @param secretKey the puzzle's key
     */
    Puzzle(int puzzle_num, SecretKey secretKey){
        this.puzzle_num = puzzle_num;
        this.secretKey = secretKey;
    }

    /**
     * puzzle number getter
     * @return a puzzle number
     */
    public int getPuzzleNumber(){
        return this.puzzle_num;
    }

    /**
     *  a key getter
     * @return the secret key of a puzzle
     */
    public SecretKey getKey(){
        return this.secretKey;
    }

    /**
     * transforming the puzzle into a byte array,
     * containing the plaintext, puzzle number and the key as bytes
     * @return the new bytes array
     */
    public byte[] getPuzzleAsBytes(){
        byte[] plaintext = new byte[16];
        byte[] number = CryptoLib.smallIntToByteArray(puzzle_num);
        byte[] key = getKey().getEncoded();

        byte[] puzzleAsBytes = ByteBuffer.allocate(plaintext.length+number.length+key.length).put(plaintext).put(number).put(key).array();

        return puzzleAsBytes;
    }



}
