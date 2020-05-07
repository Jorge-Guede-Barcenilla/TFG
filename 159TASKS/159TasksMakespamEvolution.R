library(plotly)

# Read in data
df <- read.csv("C:/Users/Jorge/Desktop/TFG 10 NOV/159TASKS/159TasksMakespamEvolution.txt", stringsAsFactors = F)

# Initialize empty plot
p <- plot_ly()

# Each task is a separate trace
# Each trace is essentially a thick line plot
# x-axis ticks are dates and handled automatically

for(i in 1:(nrow(df))){
  
  p <- add_trace(p,
                 x = c(df$NumberOfIteration[i], df$NumberOfIteration[i]+1),  # x0, x1
                 y = c(df$MakespamInIteration[i], df$MakespamInIteration[i]+1),  # y0, y1
                 mode = "lines",
                 line = list(color = "#000000" , width = 2),
                 showlegend = F,
                 hoverinfo = "text",
                 
                 # Create custom hover text
                 
                 text = paste("Iteration: ", df$Iteration[i], "<br>",
                              "Makespam: ", df$MakespamInIteration[i], "<br>"),
                 
                 evaluate = T  # needed to avoid lazy loading
  )
}

f <- list(family = "Courier New, monospace", size = 18, color = "#7f7f7f")

x <- list(title = "Iteration", titlefont = f)
y <- list(title = "Makespam", titlefont = f)

p <-layout(xaxis = x, yaxis = y)
p


