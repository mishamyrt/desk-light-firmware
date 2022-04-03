# Da(ta) P(rotocol)

This library describes a simple serial port communication protocol. The main purpose of the protocol is to get a correct message out quickly.

## Message format

Messages are an array of bytes. All messages have the same format:

```js
[0xFE, 0xEF, message_length, ...message_data]
// `message_data` repeated `message_length` times
```

## Response codes

Dap uses the response codes for the handled requests. The code shows whether the message has been successfully parsed and the command processed. The code is sent in the same format as a normal message.

* `0xEE` means success;
* `0xFF` means failure.
