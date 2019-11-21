import lombok.extern.slf4j.Slf4j;

import java.io.IOException;
import java.io.RandomAccessFile;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;
import java.nio.channels.FileLock;

@Slf4j
public class FileWorker {

    public static void writeToAvailableFile(String filename, String msg) {

        try (RandomAccessFile file = new RandomAccessFile(filename, "rw");
             FileChannel fileChannel = file.getChannel()) {
            FileLock fileLock = null;
            while (true) {
                try {
                    fileLock = fileChannel.tryLock();
                } catch (IOException exception) {
                    log.error(exception.getMessage());
                }
                if (fileLock == null) {
                    log.warn("File is locked by another process");
                } else {
                    break;
                }
            }
            log.info("File is available");
            Thread.sleep(5000);
            ByteBuffer buffer = ByteBuffer.wrap(msg.getBytes());
            buffer.put(msg.getBytes());
            buffer.flip();
            while (buffer.hasRemaining()) {
                fileChannel.write(buffer);
            }
            log.info("Message is written to file");
        } catch (InterruptedException | IOException exception) {
            log.error(exception.getMessage());
        }
    }
}
