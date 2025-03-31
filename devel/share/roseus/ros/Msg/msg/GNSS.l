;; Auto-generated. Do not edit!


(when (boundp 'Msg::GNSS)
  (if (not (find-package "MSG"))
    (make-package "MSG"))
  (shadow 'GNSS (find-package "MSG")))
(unless (find-package "MSG::GNSS")
  (make-package "MSG::GNSS"))

(in-package "ROS")
;;//! \htmlinclude GNSS.msg.html


(defclass Msg::GNSS
  :super ros::object
  :slots (_EgoAccel _IMUAccel _EgoVel _IMUVel _EgoVelocity _IMUVelocity ))

(defmethod Msg::GNSS
  (:init
   (&key
    ((:EgoAccel __EgoAccel) (make-array 3 :initial-element 0.0 :element-type :float))
    ((:IMUAccel __IMUAccel) (make-array 3 :initial-element 0.0 :element-type :float))
    ((:EgoVel __EgoVel) (make-array 3 :initial-element 0.0 :element-type :float))
    ((:IMUVel __IMUVel) (make-array 3 :initial-element 0.0 :element-type :float))
    ((:EgoVelocity __EgoVelocity) 0.0)
    ((:IMUVelocity __IMUVelocity) 0.0)
    )
   (send-super :init)
   (setq _EgoAccel __EgoAccel)
   (setq _IMUAccel __IMUAccel)
   (setq _EgoVel __EgoVel)
   (setq _IMUVel __IMUVel)
   (setq _EgoVelocity (float __EgoVelocity))
   (setq _IMUVelocity (float __IMUVelocity))
   self)
  (:EgoAccel
   (&optional __EgoAccel)
   (if __EgoAccel (setq _EgoAccel __EgoAccel)) _EgoAccel)
  (:IMUAccel
   (&optional __IMUAccel)
   (if __IMUAccel (setq _IMUAccel __IMUAccel)) _IMUAccel)
  (:EgoVel
   (&optional __EgoVel)
   (if __EgoVel (setq _EgoVel __EgoVel)) _EgoVel)
  (:IMUVel
   (&optional __IMUVel)
   (if __IMUVel (setq _IMUVel __IMUVel)) _IMUVel)
  (:EgoVelocity
   (&optional __EgoVelocity)
   (if __EgoVelocity (setq _EgoVelocity __EgoVelocity)) _EgoVelocity)
  (:IMUVelocity
   (&optional __IMUVelocity)
   (if __IMUVelocity (setq _IMUVelocity __IMUVelocity)) _IMUVelocity)
  (:serialization-length
   ()
   (+
    ;; float32[3] _EgoAccel
    (* 4    3)
    ;; float32[3] _IMUAccel
    (* 4    3)
    ;; float32[3] _EgoVel
    (* 4    3)
    ;; float32[3] _IMUVel
    (* 4    3)
    ;; float32 _EgoVelocity
    4
    ;; float32 _IMUVelocity
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32[3] _EgoAccel
     (dotimes (i 3)
       (sys::poke (elt _EgoAccel i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[3] _IMUAccel
     (dotimes (i 3)
       (sys::poke (elt _IMUAccel i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[3] _EgoVel
     (dotimes (i 3)
       (sys::poke (elt _EgoVel i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[3] _IMUVel
     (dotimes (i 3)
       (sys::poke (elt _IMUVel i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32 _EgoVelocity
       (sys::poke _EgoVelocity (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _IMUVelocity
       (sys::poke _IMUVelocity (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32[3] _EgoAccel
   (dotimes (i (length _EgoAccel))
     (setf (elt _EgoAccel i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;; float32[3] _IMUAccel
   (dotimes (i (length _IMUAccel))
     (setf (elt _IMUAccel i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;; float32[3] _EgoVel
   (dotimes (i (length _EgoVel))
     (setf (elt _EgoVel i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;; float32[3] _IMUVel
   (dotimes (i (length _IMUVel))
     (setf (elt _IMUVel i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;; float32 _EgoVelocity
     (setq _EgoVelocity (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _IMUVelocity
     (setq _IMUVelocity (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get Msg::GNSS :md5sum-) "a2a4beeb4c80c4affddeb8b52bbfae32")
(setf (get Msg::GNSS :datatype-) "Msg/GNSS")
(setf (get Msg::GNSS :definition-)
      "float32[3] EgoAccel
float32[3] IMUAccel
float32[3] EgoVel
float32[3] IMUVel
float32 EgoVelocity
float32 IMUVelocity
")



(provide :Msg/GNSS "a2a4beeb4c80c4affddeb8b52bbfae32")


