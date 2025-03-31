
(cl:in-package :asdf)

(defsystem "Msg-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "GNSS" :depends-on ("_package_GNSS"))
    (:file "_package_GNSS" :depends-on ("_package"))
  ))