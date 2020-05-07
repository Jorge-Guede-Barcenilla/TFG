library(plotly)

# Read in data
df <- read.csv("C:/Users/Jorge/Dropbox/jorge_guede/TFG RESULTADOS/159TASKS/159TasksAreasGantt.txt", stringsAsFactors = F)

# Initialize empty plot
p <- plot_ly()

# Each task is a separate trace
# Each trace is essentially a thick line plot
# x-axis ticks are dates and handled automatically

for(i in 1:(nrow(df))){
  
if(df$Area1_1StartInThisArea[i]!=df$Area1_1EndInThisArea[i])    {
  
  p <- add_trace(p,
                 x = c(df$Area1_1StartInThisArea[i], df$Area1_1EndInThisArea[i]),  # x0, x1
                 y = c(1, 1),  # y0, y1
                 mode = "lines",
                 line = list(color = df$color[i], width = 10),
                 showlegend = F,
                 hoverinfo = "text",
                 
                 # Create custom hover text
                 
                 text = paste("Task: ", df$Area1_1.Task[i], "<br>",
                              "TaskStart: ", df$Area1_1.TaskBeginning[i], "<br>",
                              "TaskEnd: ", df$Area1_1.TaskEnd[i], "<br>",
                              "TaskStartInArea: ", df$Area1_1StartInThisArea[i], "<br>",
                              "TaskEndInArea: ", df$Area1_1EndInThisArea[i], "<br>",
                              "NumberOfWorkers: ", df$Area1_1.NumberOfWorkers[i], "<br>",
                              "Worker: ", df$Area1_1.Worker[i], "<br>"),
                 
                 evaluate = T  # needed to avoid lazy loading
  )
}

if(df$Area1_2StartInThisArea[i]!=df$Area1_2EndInThisArea[i])    {
    
  p <- add_trace(p,
                 x = c(df$Area1_2StartInThisArea[i], df$Area1_2EndInThisArea[i]),   # x0, x1
                 y = c(2, 2),  # y0, y1
                 mode = "lines",
                 line = list(color = df$color[i], width = 10),
                 showlegend = F,
                 hoverinfo = "text",
                 
                 # Create custom hover text
                 
                 text = paste("Task: ", df$Area1_2.Task[i], "<br>",
                              "TaskStart: ", df$Area1_2.TaskBeginning[i], "<br>",
                              "TaskEnd: ", df$Area1_2.TaskEnd[i], "<br>",
                              "TaskStartInArea: ", df$Area1_2StartInThisArea[i], "<br>",
                              "TaskEndInArea: ", df$Area1_2EndInThisArea[i], "<br>",
                              "NumberOfWorkers: ", df$Area1_2.NumberOfWorkers[i], "<br>",
                              "Worker: ", df$Area1_2.Worker[i], "<br>"),
                 
                 evaluate = T  # needed to avoid lazy loading
  )
}

if(df$Area1_3StartInThisArea[i]!=df$Area1_3EndInThisArea[i])    {
  p <- add_trace(p,
                 x = c(df$Area1_3StartInThisArea[i], df$Area1_3EndInThisArea[i]),   # x0, x1
                 y = c(3, 3),  # y0, y1
                 mode = "lines",
                 line = list(color = df$color[i], width = 10),
                 showlegend = F,
                 hoverinfo = "text",
                 
                 # Create custom hover text
                 
                 text = paste("Task: ", df$Area1_3.Task[i], "<br>",
                              "TaskStart: ", df$Area1_3.TaskBeginning[i], "<br>",
                              "TaskEnd: ", df$Area1_3.TaskEnd[i], "<br>",
                              "TaskStartInArea: ", df$Area1_3StartInThisArea[i], "<br>",
                              "TaskEndInArea: ", df$Area1_3EndInThisArea[i], "<br>",
                              "NumberOfWorkers: ", df$Area1_3.NumberOfWorkers[i], "<br>",
                              "Worker: ", df$Area1_3.Worker[i], "<br>"),
                 
                 evaluate = T  # needed to avoid lazy loading
  )
}

if(df$Area1_4StartInThisArea[i]!=df$Area1_4EndInThisArea[i])    {
  
  p <- add_trace(p,
                 x = c(df$Area1_4StartInThisArea[i], df$Area1_4EndInThisArea[i]),   # x0, x1
                 y = c(4, 4),  # y0, y1
                 mode = "lines",
                 line = list(color = df$color[i], width = 10),
                 showlegend = F,
                 hoverinfo = "text",
                 
                 # Create custom hover text
                 
                 text = paste("Task: ", df$Area1_4.Task[i], "<br>",
                              "TaskStart: ", df$Area1_4.TaskBeginning[i], "<br>",
                              "TaskEnd: ", df$Area1_4.TaskEnd[i], "<br>",
                              "TaskStartInArea: ", df$Area1_4StartInThisArea[i], "<br>",
                              "TaskEndInArea: ", df$Area1_4EndInThisArea[i], "<br>",
                              "NumberOfWorkers: ", df$Area1_4.NumberOfWorkers[i], "<br>",
                              "Worker: ", df$Area1_4.Worker[i], "<br>"),
                 
                 evaluate = T  # needed to avoid lazy loading
  )
}
  
if(df$Area1_5StartInThisArea[i]!=df$Area1_5EndInThisArea[i])    { 
  
  p <- add_trace(p,
                 x = c(df$Area1_5StartInThisArea[i], df$Area1_5EndInThisArea[i]),   # x0, x1
                 y = c(5, 5),  # y0, y1
                 mode = "lines",
                 line = list(color = df$color[i], width = 10),
                 showlegend = F,
                 hoverinfo = "text",
                 
                 # Create custom hover text
                 
                 text = paste("Task: ", df$Area1_5.Task[i], "<br>",
                              "TaskStart: ", df$Area1_5.TaskBeginning[i], "<br>",
                              "TaskEnd: ", df$Area1_5.TaskEnd[i], "<br>",
                              "TaskStartInArea: ", df$Area1_5StartInThisArea[i], "<br>",
                              "TaskEndInArea: ", df$Area1_5EndInThisArea[i], "<br>",
                              "NumberOfWorkers: ", df$Area1_5.NumberOfWorkers[i], "<br>",
                              "Worker: ", df$Area1_5.Worker[i], "<br>"),
                 
                 evaluate = T  # needed to avoid lazy loading
  )
}

if(df$Area2_1StartInThisArea[i]!=df$Area2_1EndInThisArea[i])    {
  
  p <- add_trace(p,
                 x = c(df$Area2_1StartInThisArea[i], df$Area2_1EndInThisArea[i]),   # x0, x1
                 y = c(6, 6),  # y0, y1
                 mode = "lines",
                 line = list(color = df$color[i], width = 10),
                 showlegend = F,
                 hoverinfo = "text",
                 
                 # Create custom hover text
                 
                 text = paste("Task: ", df$Area2_1.Task[i], "<br>",
                              "TaskStart: ", df$Area2_1.TaskBeginning[i], "<br>",
                              "TaskEnd: ", df$Area2_1.TaskEnd[i], "<br>",
                              "TaskStartInArea: ", df$Area2_1StartInThisArea[i], "<br>",
                              "TaskEndInArea: ", df$Area2_1EndInThisArea[i], "<br>",
                              "NumberOfWorkers: ", df$Area2_1.NumberOfWorkers[i], "<br>",
                              "Worker: ", df$Area2_1.Worker[i], "<br>"),
                 
                           evaluate = T  # needed to avoid lazy loading
  )
}

if(df$Area2_2StartInThisArea[i]!=df$Area2_2EndInThisArea[i])    { 
  
  p <- add_trace(p,
                 x = c(df$Area2_2StartInThisArea[i], df$Area2_2EndInThisArea[i]),   # x0, x1
                 y = c(7, 7),  # y0, y1
                 mode = "lines",
                 line = list(color = df$color[i], width = 10),
                 showlegend = F,
                 hoverinfo = "text",
                 
                 # Create custom hover text
                 
                 text = paste("Task: ", df$Area2_2.Task[i], "<br>",
                              "TaskStart: ", df$Area2_2.TaskBeginning[i], "<br>",
                              "TaskEnd: ", df$Area2_2.TaskEnd[i], "<br>",
                              "TaskStartInArea: ", df$Area2_2StartInThisArea[i], "<br>",
                              "TaskEndInArea: ", df$Area2_2EndInThisArea[i], "<br>",
                              "NumberOfWorkers: ", df$Area2_2.NumberOfWorkers[i], "<br>",
                              "Worker: ", df$Area2_2.Worker[i], "<br>"),
                 
                 evaluate = T  # needed to avoid lazy loading
  )
}

if(df$Area2_3StartInThisArea[i]!=df$Area2_3EndInThisArea[i])    {
  
  p <- add_trace(p,
                 x = c(df$Area2_3StartInThisArea[i], df$Area2_3EndInThisArea[i]),   # x0, x1
                 y = c(8, 8),  # y0, y1
                 mode = "lines",
                 line = list(color = df$color[i], width = 10),
                 showlegend = F,
                 hoverinfo = "text",
                 
                 # Create custom hover text
                 
                 text = paste("Task: ", df$Area2_3.Task[i], "<br>",
                              "TaskStart: ", df$Area2_3.TaskBeginning[i], "<br>",
                              "TaskEnd: ", df$Area2_3.TaskEnd[i], "<br>",
                              "TaskStartInArea: ", df$Area2_3StartInThisArea[i], "<br>",
                              "TaskEndInArea: ", df$Area2_3EndInThisArea[i], "<br>",
                              "NumberOfWorkers: ", df$Area2_3.NumberOfWorkers[i], "<br>",
                              "Worker: ", df$Area2_3.Worker[i], "<br>"),
                 
                 evaluate = T  # needed to avoid lazy loading
  )
}
}

f <- list(family = "Courier New, monospace", size = 18, color = "#7f7f7f")

x <- list(title = "Time", titlefont = f)

y <- list(title = "Area", titlefont = f)

p <-layout(xaxis = x, yaxis = y)
p


