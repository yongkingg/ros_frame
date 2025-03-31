; Auto-generated. Do not edit!


(cl:in-package Msg-msg)


;//! \htmlinclude GNSS.msg.html

(cl:defclass <GNSS> (roslisp-msg-protocol:ros-message)
  ((EgoAccel
    :reader EgoAccel
    :initarg :EgoAccel
    :type (cl:vector cl:float)
   :initform (cl:make-array 3 :element-type 'cl:float :initial-element 0.0))
   (IMUAccel
    :reader IMUAccel
    :initarg :IMUAccel
    :type (cl:vector cl:float)
   :initform (cl:make-array 3 :element-type 'cl:float :initial-element 0.0))
   (EgoVel
    :reader EgoVel
    :initarg :EgoVel
    :type (cl:vector cl:float)
   :initform (cl:make-array 3 :element-type 'cl:float :initial-element 0.0))
   (IMUVel
    :reader IMUVel
    :initarg :IMUVel
    :type (cl:vector cl:float)
   :initform (cl:make-array 3 :element-type 'cl:float :initial-element 0.0))
   (EgoVelocity
    :reader EgoVelocity
    :initarg :EgoVelocity
    :type cl:float
    :initform 0.0)
   (IMUVelocity
    :reader IMUVelocity
    :initarg :IMUVelocity
    :type cl:float
    :initform 0.0))
)

(cl:defclass GNSS (<GNSS>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GNSS>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GNSS)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name Msg-msg:<GNSS> is deprecated: use Msg-msg:GNSS instead.")))

(cl:ensure-generic-function 'EgoAccel-val :lambda-list '(m))
(cl:defmethod EgoAccel-val ((m <GNSS>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Msg-msg:EgoAccel-val is deprecated.  Use Msg-msg:EgoAccel instead.")
  (EgoAccel m))

(cl:ensure-generic-function 'IMUAccel-val :lambda-list '(m))
(cl:defmethod IMUAccel-val ((m <GNSS>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Msg-msg:IMUAccel-val is deprecated.  Use Msg-msg:IMUAccel instead.")
  (IMUAccel m))

(cl:ensure-generic-function 'EgoVel-val :lambda-list '(m))
(cl:defmethod EgoVel-val ((m <GNSS>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Msg-msg:EgoVel-val is deprecated.  Use Msg-msg:EgoVel instead.")
  (EgoVel m))

(cl:ensure-generic-function 'IMUVel-val :lambda-list '(m))
(cl:defmethod IMUVel-val ((m <GNSS>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Msg-msg:IMUVel-val is deprecated.  Use Msg-msg:IMUVel instead.")
  (IMUVel m))

(cl:ensure-generic-function 'EgoVelocity-val :lambda-list '(m))
(cl:defmethod EgoVelocity-val ((m <GNSS>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Msg-msg:EgoVelocity-val is deprecated.  Use Msg-msg:EgoVelocity instead.")
  (EgoVelocity m))

(cl:ensure-generic-function 'IMUVelocity-val :lambda-list '(m))
(cl:defmethod IMUVelocity-val ((m <GNSS>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Msg-msg:IMUVelocity-val is deprecated.  Use Msg-msg:IMUVelocity instead.")
  (IMUVelocity m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GNSS>) ostream)
  "Serializes a message object of type '<GNSS>"
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'EgoAccel))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'IMUAccel))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'EgoVel))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'IMUVel))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'EgoVelocity))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'IMUVelocity))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GNSS>) istream)
  "Deserializes a message object of type '<GNSS>"
  (cl:setf (cl:slot-value msg 'EgoAccel) (cl:make-array 3))
  (cl:let ((vals (cl:slot-value msg 'EgoAccel)))
    (cl:dotimes (i 3)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  (cl:setf (cl:slot-value msg 'IMUAccel) (cl:make-array 3))
  (cl:let ((vals (cl:slot-value msg 'IMUAccel)))
    (cl:dotimes (i 3)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  (cl:setf (cl:slot-value msg 'EgoVel) (cl:make-array 3))
  (cl:let ((vals (cl:slot-value msg 'EgoVel)))
    (cl:dotimes (i 3)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  (cl:setf (cl:slot-value msg 'IMUVel) (cl:make-array 3))
  (cl:let ((vals (cl:slot-value msg 'IMUVel)))
    (cl:dotimes (i 3)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'EgoVelocity) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'IMUVelocity) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GNSS>)))
  "Returns string type for a message object of type '<GNSS>"
  "Msg/GNSS")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GNSS)))
  "Returns string type for a message object of type 'GNSS"
  "Msg/GNSS")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GNSS>)))
  "Returns md5sum for a message object of type '<GNSS>"
  "a2a4beeb4c80c4affddeb8b52bbfae32")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GNSS)))
  "Returns md5sum for a message object of type 'GNSS"
  "a2a4beeb4c80c4affddeb8b52bbfae32")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GNSS>)))
  "Returns full string definition for message of type '<GNSS>"
  (cl:format cl:nil "float32[3] EgoAccel~%float32[3] IMUAccel~%float32[3] EgoVel~%float32[3] IMUVel~%float32 EgoVelocity~%float32 IMUVelocity~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GNSS)))
  "Returns full string definition for message of type 'GNSS"
  (cl:format cl:nil "float32[3] EgoAccel~%float32[3] IMUAccel~%float32[3] EgoVel~%float32[3] IMUVel~%float32 EgoVelocity~%float32 IMUVelocity~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GNSS>))
  (cl:+ 0
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'EgoAccel) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'IMUAccel) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'EgoVel) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'IMUVel) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GNSS>))
  "Converts a ROS message object to a list"
  (cl:list 'GNSS
    (cl:cons ':EgoAccel (EgoAccel msg))
    (cl:cons ':IMUAccel (IMUAccel msg))
    (cl:cons ':EgoVel (EgoVel msg))
    (cl:cons ':IMUVel (IMUVel msg))
    (cl:cons ':EgoVelocity (EgoVelocity msg))
    (cl:cons ':IMUVelocity (IMUVelocity msg))
))
