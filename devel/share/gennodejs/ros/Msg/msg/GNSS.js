// Auto-generated. Do not edit!

// (in-package Msg.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class GNSS {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.EgoAccel = null;
      this.IMUAccel = null;
      this.EgoVel = null;
      this.IMUVel = null;
      this.EgoVelocity = null;
      this.IMUVelocity = null;
    }
    else {
      if (initObj.hasOwnProperty('EgoAccel')) {
        this.EgoAccel = initObj.EgoAccel
      }
      else {
        this.EgoAccel = new Array(3).fill(0);
      }
      if (initObj.hasOwnProperty('IMUAccel')) {
        this.IMUAccel = initObj.IMUAccel
      }
      else {
        this.IMUAccel = new Array(3).fill(0);
      }
      if (initObj.hasOwnProperty('EgoVel')) {
        this.EgoVel = initObj.EgoVel
      }
      else {
        this.EgoVel = new Array(3).fill(0);
      }
      if (initObj.hasOwnProperty('IMUVel')) {
        this.IMUVel = initObj.IMUVel
      }
      else {
        this.IMUVel = new Array(3).fill(0);
      }
      if (initObj.hasOwnProperty('EgoVelocity')) {
        this.EgoVelocity = initObj.EgoVelocity
      }
      else {
        this.EgoVelocity = 0.0;
      }
      if (initObj.hasOwnProperty('IMUVelocity')) {
        this.IMUVelocity = initObj.IMUVelocity
      }
      else {
        this.IMUVelocity = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type GNSS
    // Check that the constant length array field [EgoAccel] has the right length
    if (obj.EgoAccel.length !== 3) {
      throw new Error('Unable to serialize array field EgoAccel - length must be 3')
    }
    // Serialize message field [EgoAccel]
    bufferOffset = _arraySerializer.float32(obj.EgoAccel, buffer, bufferOffset, 3);
    // Check that the constant length array field [IMUAccel] has the right length
    if (obj.IMUAccel.length !== 3) {
      throw new Error('Unable to serialize array field IMUAccel - length must be 3')
    }
    // Serialize message field [IMUAccel]
    bufferOffset = _arraySerializer.float32(obj.IMUAccel, buffer, bufferOffset, 3);
    // Check that the constant length array field [EgoVel] has the right length
    if (obj.EgoVel.length !== 3) {
      throw new Error('Unable to serialize array field EgoVel - length must be 3')
    }
    // Serialize message field [EgoVel]
    bufferOffset = _arraySerializer.float32(obj.EgoVel, buffer, bufferOffset, 3);
    // Check that the constant length array field [IMUVel] has the right length
    if (obj.IMUVel.length !== 3) {
      throw new Error('Unable to serialize array field IMUVel - length must be 3')
    }
    // Serialize message field [IMUVel]
    bufferOffset = _arraySerializer.float32(obj.IMUVel, buffer, bufferOffset, 3);
    // Serialize message field [EgoVelocity]
    bufferOffset = _serializer.float32(obj.EgoVelocity, buffer, bufferOffset);
    // Serialize message field [IMUVelocity]
    bufferOffset = _serializer.float32(obj.IMUVelocity, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type GNSS
    let len;
    let data = new GNSS(null);
    // Deserialize message field [EgoAccel]
    data.EgoAccel = _arrayDeserializer.float32(buffer, bufferOffset, 3)
    // Deserialize message field [IMUAccel]
    data.IMUAccel = _arrayDeserializer.float32(buffer, bufferOffset, 3)
    // Deserialize message field [EgoVel]
    data.EgoVel = _arrayDeserializer.float32(buffer, bufferOffset, 3)
    // Deserialize message field [IMUVel]
    data.IMUVel = _arrayDeserializer.float32(buffer, bufferOffset, 3)
    // Deserialize message field [EgoVelocity]
    data.EgoVelocity = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [IMUVelocity]
    data.IMUVelocity = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 56;
  }

  static datatype() {
    // Returns string type for a message object
    return 'Msg/GNSS';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'a2a4beeb4c80c4affddeb8b52bbfae32';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32[3] EgoAccel
    float32[3] IMUAccel
    float32[3] EgoVel
    float32[3] IMUVel
    float32 EgoVelocity
    float32 IMUVelocity
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new GNSS(null);
    if (msg.EgoAccel !== undefined) {
      resolved.EgoAccel = msg.EgoAccel;
    }
    else {
      resolved.EgoAccel = new Array(3).fill(0)
    }

    if (msg.IMUAccel !== undefined) {
      resolved.IMUAccel = msg.IMUAccel;
    }
    else {
      resolved.IMUAccel = new Array(3).fill(0)
    }

    if (msg.EgoVel !== undefined) {
      resolved.EgoVel = msg.EgoVel;
    }
    else {
      resolved.EgoVel = new Array(3).fill(0)
    }

    if (msg.IMUVel !== undefined) {
      resolved.IMUVel = msg.IMUVel;
    }
    else {
      resolved.IMUVel = new Array(3).fill(0)
    }

    if (msg.EgoVelocity !== undefined) {
      resolved.EgoVelocity = msg.EgoVelocity;
    }
    else {
      resolved.EgoVelocity = 0.0
    }

    if (msg.IMUVelocity !== undefined) {
      resolved.IMUVelocity = msg.IMUVelocity;
    }
    else {
      resolved.IMUVelocity = 0.0
    }

    return resolved;
    }
};

module.exports = GNSS;
