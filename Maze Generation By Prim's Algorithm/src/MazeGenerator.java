import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;

import javax.imageio.ImageIO;
import javax.swing.*;

public class MazeGenerator extends Canvas
{
	private static final Random rand = new Random();
	
	//the WIDTH & HEIGHT determines pixles of the Image
	
	private static final int WIDTH = 80;
	private static final int HEIGHT = 60;
	private static final int TILE_WIDTH = 10;
	private static final int TILE_HEIGHT = 10;

	private List<Vector2I> maze = new ArrayList<>();
	private Map<Vector2I, Color> colors = new HashMap<>();

	private int step = 0;

	public void paint(Graphics g)
	{
		super.paint(g);
		g.drawLine(0, 0, 0, HEIGHT * TILE_HEIGHT);
		g.drawLine(0, 0, WIDTH * TILE_WIDTH, 0);
		g.drawLine(WIDTH * TILE_WIDTH, 0, WIDTH * TILE_WIDTH, HEIGHT * TILE_HEIGHT);
		g.drawLine(0, HEIGHT * TILE_HEIGHT, WIDTH * TILE_WIDTH, HEIGHT * TILE_HEIGHT);

		//Use this line instead of the one below this to see the maze progressively generate
		List<Vector2I> mazeSteped = maze.subList(0, step);
		
		//List<Vector2I> mazeSteped = maze;

		for(int y = 0; y < HEIGHT; y++)
		{
			for(int x = 0; x < WIDTH; x++)
			{
				int current = (y * WIDTH) + x;
				int lower = ((y + 1) * WIDTH) + x;
				if(!mazeSteped.contains(new Vector2I(current, lower)))
					g.drawLine(x * TILE_WIDTH, (y + 1) * TILE_HEIGHT, (x + 1) * TILE_WIDTH, (y + 1) * TILE_HEIGHT);

				if(!mazeSteped.contains(new Vector2I(current, current + 1)))
					g.drawLine((x + 1) * TILE_WIDTH, y * TILE_HEIGHT, (x + 1) * TILE_WIDTH, (y + 1) * TILE_HEIGHT);

				if(colors.containsKey(new Vector2I(x, y)))
				{
					g.setColor(colors.get(new Vector2I(x, y)));
					g.fillRect(x * TILE_WIDTH, y * TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT);
					g.setColor(Color.BLACK);
				}
			}
		}
	}

	public void generate()
	{
		List<Integer> visited = new ArrayList<>();
		List<Vector2I> toVisit = new ArrayList<>();
		
		//type the desired picture name below to see it in the output

		//if you don't want to load image just comment the below code
		
		loadImageIn(visited, "tree.png");

		visited.add(0);
		toVisit.add(new Vector2I(0, 1));
		toVisit.add(new Vector2I(0, WIDTH));

		while(toVisit.size() > 0)
		{
			int randomIndex = rand.nextInt(toVisit.size());
			Vector2I nextPath = toVisit.remove(randomIndex);

			if(visited.contains(nextPath.end))
				continue;

			if(nextPath.start > nextPath.end)
				maze.add(new Vector2I(nextPath.end, nextPath.start));
			else
				maze.add(nextPath);

			visited.add(nextPath.end);

			int above = nextPath.end - WIDTH;
			if(above > 0 && !visited.contains(above))
				toVisit.add(new Vector2I(nextPath.end, above));

			int left = nextPath.end - 1;
			if(left % WIDTH != WIDTH - 1 && !visited.contains(left))
				toVisit.add(new Vector2I(nextPath.end, left));

			int right = nextPath.end + 1;
			if(right % WIDTH != 0 && !visited.contains(right))
				toVisit.add(new Vector2I(nextPath.end, right));

			int below = nextPath.end + WIDTH;
			if(below < WIDTH * HEIGHT && !visited.contains(below))
				toVisit.add(new Vector2I(nextPath.end, below));
		}

		 //Uncomment this to show the maze progressively generate
		
		Timer timer = new Timer(700, (e) ->
		{
	     	step();
		MazeGenerator.this.repaint();
		});
		timer.setRepeats(true);
		timer.start();
	}

	public void loadImageIn(List<Integer> visited, String file)
	{
		try
		{
			BufferedImage image = ImageIO.read(new File("res/" + file));
			for(int y = 0; y < image.getHeight(); y++)
			{
				for(int x = 0; x < image.getWidth(); x++)
				{
					int rgb = image.getRGB(x, y);
					if(rgb != -1)
					{
						visited.add((y * WIDTH) + x);
						colors.put(new Vector2I(x, y), new Color(rgb));
					}
				}
			}
		} catch(IOException e)
		{
			e.printStackTrace();
		}
	}

	public void step()
	{
		step++;
		if(step >= maze.size())
			step = maze.size() - 1;
	}

	public static void main(String[] args)
	{
		MazeGenerator mazeGen = new MazeGenerator();
		mazeGen.generate();
		mazeGen.setSize(830, 650);
		JFrame frame = new JFrame("Maze Generator");
		frame.add(mazeGen);
		frame.setSize(830, 650);
		frame.setVisible(true);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
