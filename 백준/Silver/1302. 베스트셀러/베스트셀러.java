import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.Optional;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        HashMap<String,Integer> bookList = new HashMap<String,Integer>();

        for(int i=0;i<n;i++) {
            String bookName = br.readLine();

            if(bookList.containsKey(bookName)) {
                bookList.put(bookName, bookList.get(bookName) + 1);
            }
            else {
                bookList.put(bookName, 1);
            }
        }

        Optional<Entry<String,Integer>> maxEntry = bookList.entrySet()
                .stream()
                .max((entry1, entry2) -> {
                    int valueCompare = Integer.compare(entry1.getValue(), entry2.getValue());
                    
                    if(valueCompare == 0) {
                        return entry2.getKey().compareTo(entry1.getKey());
                    }
                    return valueCompare;
                });
        
        if(maxEntry.isPresent()) {
            bw.write(maxEntry.get().getKey());
        }
        bw.flush();
        bw.close();
    }
}
