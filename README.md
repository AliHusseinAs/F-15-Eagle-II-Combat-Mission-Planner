# F-15-Eagle-II-Combat-Mission-Planner

This C++ project simulates a mission planning tool for the F-15 Eagle II fighter jet. The program is divided into two main classes: calculations and dataValidation. Below is a breakdown of the functionality provided by the program:
User Authentication:
The dataValidation class ensures that only authorized pilots can access the mission planning functionalities. It compares the entered pilot ID against a predefined list of valid IDs.
Mission Planning:
Once authenticated, the calculations class guides the pilot through a series of inputs to plan the mission:
Distance Calculation: The program calculates the distance between the current location and the target location using the Euclidean distance formula. This distance is then used to estimate travel time based on the jet's speed.
Fuel Estimation: The program prompts the pilot to enter the current fuel percentage. It checks if the reserve fuel is adequate for the mission and gives recommendations accordingly.
Mission-Specific Calculations: The program offers different calculations based on the type of mission:
Flight Time: Calculates whether the jet has enough fuel for the journey considering its initial and final weights.
Air Interaction: Considers the weight of additional missiles and calculates the range.
Air-to-Earth Combat: Focuses on the requirements for air-to-ground missions, accounting for additional armaments.
Dangerous Zone: Takes into account potential threats like surface-to-air missiles (SAMs) and calculates the necessary range and fuel requirements.
Additional Features:
Mission Feedback: Depending on the calculations, the program provides feedback on whether the jet has enough fuel for the entire trip, and whether any stops for refueling are necessary.
Safety Recommendations: The program gives strategic advice, such as the importance of carrying specific missiles (e.g., AIM-120 AMRAAM, LRASM) based on the mission type.
User Interface:
The program's interface is text-based and prompts the user to input necessary details step by step. It also provides feedback and instructions in a clear and concise manner.
