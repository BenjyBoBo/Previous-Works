import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.List;
import javax.swing.DefaultListModel;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JScrollPane;
import javax.swing.ListSelectionModel;
import javax.swing.border.EtchedBorder;
import javax.swing.border.TitledBorder;

public class SenatorGUI {
    
    private JFrame frame;
    private JList<String> senList;
    
    public SenatorGUI(List<Senator> senatorList) {
        
        //initializes JFrame
        frame  = new JFrame("Senatorz V2");        
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(new Dimension(712, 712));
        Container contentPane = frame.getContentPane();
        
        //creates the Senator name JList and adds a JScrollPane
        DefaultListModel<String> names = new DefaultListModel<>();
        senList = new JList<>(names);
        senList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        senList.setLayoutOrientation(JList.VERTICAL);
        senList.setBorder(new TitledBorder(new EtchedBorder()));
        JScrollPane scroll = new JScrollPane(senList);
        contentPane.add(scroll, BorderLayout.LINE_START);
        
        //adds senator names to JList
        for (int i = 0; i < senatorList.size(); i++) {
            names.addElement(senatorList.get(i).getFullName());
        }
        
        //initializes artLabel JLabel
        JLabel artLabel = new JLabel();
        artLabel.setHorizontalTextPosition(JLabel.CENTER);
        artLabel.setVerticalTextPosition(JLabel.BOTTOM);
        contentPane.add(artLabel, BorderLayout.CENTER);
        
        //detects mouse click on JList and displays picture and info
        //for the specified senator
        senList.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent evt) {
                JList<?> list = (JList<?>) evt.getSource();
                int index = list.locationToIndex(evt.getPoint());
                Senator currSen = senatorList.get(index);
                String info = currSen.getFullName() + " (" + currSen.getParty()
                                            + "-" + currSen.getState() + ")";
                ImageIcon image;
                image = new ImageIcon(senatorList.get(index).getPhotoURL());
                artLabel.setIcon(image);
                artLabel.setText(info);
            }
        });
    }
    
    
    
    public void display() {
        frame.setVisible(true);
    }
    
    public static void main(String args[]) throws IOException {
        InputStream ips = new FileInputStream("senators.json");
        new SenatorGUI(SenatorListReader.readSenatorList(ips)).display();
    }
}
