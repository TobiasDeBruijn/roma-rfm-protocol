# Protocol specification
Protocol specification for Roma RFM-connected modules.

## Command
Command execution protocol.
Used for informing a device it should do something, i.e. execute a command it is given.

Identifier: 0x01

### Byte-for-byte:

| Byte index | Type                        | Description       |
|------------|-----------------------------|-------------------|
| 0          | uint8                       | Packet identifier |
| 1-4        | uint32                      | Serial number     |
| 5-6        | uint16                      | ACK ID            |
| 7          | uint8                       | Flags             |
| 8-9        | uint16                      | Command type      |
| 10..       | Refer to command data table | Command data      | 

#### Flags

| Bit | Description |
|-----|-------------|
| 0   | isAck       |

#### Command types

| Identifier | Command type |
|------------|--------------|
| 0x01       | On/Off       |

#### Command data
Note that the byte index provided in the tables below should be added to the first byte of the `Command data` section in the packet itself.

###### Type 0x01

| Byte index | Type  | Description   |
|------------|-------|---------------|
| 0          | bool  | On/Off status |
| 1          | uint8 | Relay index   |

## Settings
Settings communication protocol. Used for informing a device of its settings.

Identifier: 0x02

### Byte-for-byte
| Byte index | Type                         | Description        |
|------------|------------------------------|--------------------|
| 0          | uint8                        | Packet identifier  |
| 1-4        | uint32                       | Serial number      |
| 5-6        | uint16                       | ACK ID             |
| 7          | uint8                        | Flags              |
| 8          | uint8                        | Settings data type |
| 9..        | Refer to settings data table | Settings data      |

#### Flags

| Bit | Description |
|-----|-------------|
| 0   | isAck       |
| 1   | isRequest   |

#### Settings data type

| Identifier | Settings type                                       |
|------------|-----------------------------------------------------|
| 0x01       | Settings for device capable of switching relays     |

#### Settings data
Note that the byte index provided in the tables below should be added to the first byte of the `Settings data` section in the packet itself.

###### Type 0x01

| Byte index | Type | Description            |
|------------|------|------------------------|
| 0          | bool | Relay 1 default status |
| 1          | bool | Relay 2 default status |

