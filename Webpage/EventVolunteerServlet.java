import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/EventVolunteerServlet")
public class EventVolunteerServlet extends HttpServlet {

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        // Debugging Output (Server-Side Logs)
        System.out.println("Form Data Received:");

        // Volunteer Form Data
        String opportunityName = request.getParameter("opportunityName");
        String date = request.getParameter("date");
        String time = request.getParameter("time");
        String addressLine1 = request.getParameter("addressLine1");
        String addressLine2 = request.getParameter("addressLine2");
        String cityStateZip = request.getParameter("cityStateZip");
        String volunteersNeeded = request.getParameter("volunteersNeeded");
        String description = request.getParameter("description");
        String[] organizers = request.getParameterValues("organizers[]");
        String[] volunteers = request.getParameterValues("volunteers[]");

        // Event Form Data
        String eventName = request.getParameter("eventName");
        String eventDate = request.getParameter("eventDate");
        String eventTime = request.getParameter("eventTime");
        String eventAddressLine1 = request.getParameter("eventAddressLine1");
        String eventAddressLine2 = request.getParameter("eventAddressLine2");
        String eventCityStateZip = request.getParameter("eventCityStateZip");
        String eventDescription = request.getParameter("eventDescription");

        // Log Volunteer Data (if present)
        if (opportunityName != null) {
            System.out.println("Opportunity Name: " + opportunityName);
            System.out.println("Date: " + date);
            System.out.println("Time: " + time);
            System.out.println("Address: " + addressLine1 + " " + addressLine2 + ", " + cityStateZip);
            System.out.println("Volunteers Needed: " + volunteersNeeded);
            System.out.println("Description: " + description);

            if (organizers != null) {
                System.out.println("Organizers:");
                for (String organizer : organizers) {
                    System.out.println("- " + organizer);
                }
            }

            if (volunteers != null) {
                System.out.println("Volunteers:");
                for (String volunteer : volunteers) {
                    System.out.println("- " + volunteer);
                }
            }
        }

        // Log Event Data (if present)
        if (eventName != null) {
            System.out.println("Event Name: " + eventName);
            System.out.println("Date: " + eventDate);
            System.out.println("Time: " + eventTime);
            System.out.println("Address: " + eventAddressLine1 + " " + eventAddressLine2 + ", " + eventCityStateZip);
            System.out.println("Description: " + eventDescription);
        }

        
        out.println("Data received and logged.");
    }
}