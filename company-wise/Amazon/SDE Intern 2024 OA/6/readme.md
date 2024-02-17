A bardcode scanner can be configured by scanning a series of barcodes in the correct order. Barcode configurations are encoded into a single string and stored as a blob in the backend system. The client requests the configuration from the backend configuration service, and then needs to be present the configurations in the correct order.

The encoded configuration string is a series of pairs separated by |. The original index value is a 4 digit numeric prefixed with zeros. For example, the first configuration will be represented as 0001.
The goals are to 1) validate the configuration string, and 2) provide the configuration client the configuration values in the order required to sucessfully configure the barcode scanner.

Validation conditions
All configurations must be separated by a "|" character.
Configurations cannot skip a number in the ordering. IF there are 3 configuration strings, there must be a 1,2, and 3 index.
Configuration values are alphanumeric and may contain no other characters.
Configuration value lenght is exactly 10 characters.
Ordinal indices may not repeat, for example there cannot be two occurences of the number "1".
Each configuration value is unique, configurations do not repeat.
"0000" is no a valid ordinal index.
if a configuration string is not valid. return ["Invalid configuration"]

Example

Happy path

configuration = "0002f7c22e7904|000176a3a4d214|000305d29f4a4b"

Based on the order value, the expected output of this configuration string is:
Output
[
"76a3a4d214", # 0001
"f7c22e7904", # 0002
"05d29f4a4b" # 0003
]
Constraints and Assumptions
1 <= order <= 9999
1 <= count(configuration) <= 9,999
Order values may not be unique or complete.
Configuration values are not always unique, the same configuration may appear in multiple configuration steps.
Sample Case 0

configuration =

0001LAJ5KBX9H8|0003UKURNK403F|0002MO6K1Z9WFA|0004OWRXZFMS2C

Sample Output:
LAJ5KBX9H8
MO6K1Z9WFA
UKURNK403F
OWRXZFMS2C