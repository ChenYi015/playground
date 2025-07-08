object PatternMatchExample3 extends App {
  sealed trait Notification

  case class Email(sender: String, title: String, body: String)
      extends Notification

  case class SMS(caller: String, message: String) extends Notification

  case class VoiceRecording(contactName: String, link: String)
      extends Notification

  def showNotification(notification: Notification): String = {
    notification match {
      case Email(sender, title, _) =>
        s"You got an email from $sender with title: $title"
      case SMS(number, message) =>
        s"You got an SMS from $number! Message: $message"
      case VoiceRecording(name, link) =>
        s"You received a Voice Recording from $name! Click the link to hear it: $link"
    }
  }

  val someEmail =
    Email("test@email.com", "Important message", "Please reply ASAP.")
  val someSms = SMS("12345", "Are you there?")
  val someVoiceRecording = VoiceRecording("Tom", "voicerecording.org/id/123")

  println(showNotification(someEmail))
  // You got an email from test@email.com with title: Important message

  println(showNotification(someSms))
  // You got an SMS from 12345! Message: Are you there?

  println(showNotification(someVoiceRecording))
  // You received a Voice Recording from Tom! Click the link to hear it: voicerecording.org/id/123
}
