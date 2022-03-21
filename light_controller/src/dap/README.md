# Da(ta) P(rotocol)

This library describes a simple serial port communication protocol. The main purpose of the protocol is to get a correct message out quickly. There is no correction, but there is detection of a transmission error.

## Message format

Messages are an array of bytes. All messages have the same format:

```js
[0xFE, 0xEF, message_length, ...message_data, checksum]
// `message_data` repeated `message_length` times
```

## Checksum

The checksum is the addition of all the numbers in the message. When 256 is reached, the value is reset to 0. Example:

```cpp
uint8_t dapChecksum(uint8_t *message, size_t message_length) {
  int checksum = 0;
  for (int i = 0; i < message_length; i++) {
    checksum += message[i];
    if (checksum > 255) {
      checksum -= 255;
    }
  }
  return checksum;
}
```

If the checksum does not match, an error will be returned and the message will be skipped.

## Response codes

Dap uses the response codes for the handled requests. The code shows whether the message has been successfully parsed and the command processed. The code is sent in the same format as a normal message.

* `0xEE` means success;
* `0xFF` means failure.
