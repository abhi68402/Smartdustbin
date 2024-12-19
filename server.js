const express = require('express');
const axios = require('axios');
const path = require('path');

const app = express();
const PORT = 3000;

// Serve static files like HTML, CSS, JS
app.use(express.static('public'));

// API route to get live data from Blynk
app.get('/api/dustbin-status', async (req, res) => {
  try {
    const response = await axios.get('https://blynk.cloud/external/api/get?token=HGwAXJ8VGOw15Tt8ge2vTjncMwYFt2lj&V0');
    const fillLevel = response.data;  // Assuming the API returns a fill level
    res.json({ fillLevel });
  } catch (error) {
    res.status(500).json({ error: 'Failed to fetch dustbin status' });
  }
});

// Start the server
app.listen(PORT, () => {
  console.log(`Server is running on http://localhost:${PORT}`);
});
