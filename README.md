# Smart Dustbin Management System

The **Smart Dustbin Management System** is a web-based application designed to monitor and manage the fill levels of Smart module Enabled dustbins in a city or campus. It helps to optimize waste collection routes and improve waste management efficiency.Below is a insight of our Webpage

 ![alt image](https://github.com/abhi68402/Smartdustbin/blob/main/Screenshot%202025-03-16%20214708.png?raw=true)

## Features
- **SmartMdodule**: Each Dustbin has a module installed in inside of the bin,It consists of ESP32 and HCSRO4 Sensors to calculate the fill level of the bin.
     
  ![Module and its installation](https://github.com/abhi68402/Smartdustbin/blob/main/Screenshot%202025-03-16%20213547.png?raw=true)
  

  ![alt image](https://github.com/abhi68402/Smartdustbin/blob/main/WhatsApp%20Image%202024-12-09%20at%2020.37.18_a2862218.jpg?raw=true)

- **Real-Time Dustbin Monitoring**: Displays the current fill levels of dustbins tracked as per our modules.

  ![Module and its installation](https://github.com/abhi68402/Smartdustbin/blob/main/Screenshot%202025-03-16%20at%2021-52-47%20GITAM%20Waste%20Bins%20%E2%80%93%20Google%20My%20Maps.png?raw=true)
 
- **Optimized Route Calculation**: Allows users to select dustbins and calculates the most efficient route for collection.
- **Fill Level Status**: Visual bars and color-coded labels indicate dustbin status (Low, Medium, High).
- **Interactive Map**: View the location of dustbins on a map for optimized collection routes.
- **User-Friendly Interface**: Simple and responsive design for easy use on desktop and mobile devices.

## Tech Stack
- **Arduino/C++**: For Developing smart module that can take readings of Dustbin Fill Level
- **HTML/CSS**: For building the structure and style of the web application.
- **JavaScript**:To handle the interaction logic and map integration.
- **Node.Js**: To Handle server side components and register the data sent by modules.
- **Google Maps API**: For rendering maps and calculating optimized routes.
  
## Installation and Setup

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/smart-dustbin-management.git
