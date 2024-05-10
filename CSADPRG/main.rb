# Last names: Feliciano, Ty, Rodriguez, Clemente
# Language: Ruby
# Paradigm(s): Object-Oriented, Functional

require 'time' # for parsing time

# Define the character length for each table row
COLUMN_LENGTH = 40

def generate_row(*row_items)
  i = 0 # iterator

  print '│'
  row_items.length.times do
    spaces_count = COLUMN_LENGTH - row_items[i].length

    if spaces_count.positive?
      spaces = ' ' * spaces_count
      print "#{row_items[i]}#{spaces}"
    else
      print row_items[i]
    end

    i += 1

    print '│ ' if i != row_items.length
  end
  puts '│'
end

def generate_header(header, row_nums)
  i = 0 # iterator

  print '│'
  spaces_count = COLUMN_LENGTH * row_nums - header.length + row_nums

  if spaces_count.positive?
    spaces = ' ' * spaces_count
    print "#{header}#{spaces}"
  else
    print header
  end
  puts '│'
end

def generate_table_top(row_items, middle_border = true)
  ctr = row_items

  print '┌'
  if row_items == 1
    COLUMN_LENGTH.times { print '─' }
  else
    row_items.times do
      COLUMN_LENGTH.times { print '─' }
      ctr -= 1

      print ctr != 0 && middle_border == true ? '┬' : '─'
    end
  end
  puts '┐'
end

def generate_table_middle(row_items)
  ctr = row_items

  print '├'
  if row_items == 1
    COLUMN_LENGTH.times { print '─' }
  else
    row_items.times do
      COLUMN_LENGTH.times { print '─' }
      ctr -= 1

      print ctr != 0 ? '┬' : '─'
    end

  end
  puts '┤'
end

def generate_table_bottom(row_items, middle_border = true)
  ctr = row_items

  print '└'
  if row_items == 1
    COLUMN_LENGTH.times { print '─' }
  else
    row_items.times do
      COLUMN_LENGTH.times { print '─' }
      ctr -= 1

      print ctr != 0 && middle_border == true ? '┴' : '─'
    end
  end
  puts '┘'
end

class MP_3_Ruby
  attr_accessor :initial_daily_salary, :max_regular_work_hours, :workdays, :initial_day_type, :initial_in_time,
                :initial_out_time, :salary_array

  def initialize
    @initial_daily_salary = 500.00
    @max_regular_work_hours = 8
    @workdays = 5
    @initial_day_type = 'Normal Day'
    @initial_in_time = '0900'
    @initial_out_time = '0900'
    @salary_array = Array.new(7)
  end

  def modify_configurations
    generate_table_top(2, false)
    generate_header('Modify Default Configurations', 2)
    generate_table_middle(2)
    generate_row('[1] Daily Salary', "#{initial_daily_salary}")
    generate_row('[2] Max Regular Work Hours', "#{max_regular_work_hours}")
    generate_row('[3] Number of Workdays', "#{workdays}")
    generate_row('[4] Initial Day Type', "#{initial_day_type}")
    generate_row('[5] IN time', "#{initial_in_time}")
    generate_row('[6] OUT time', "#{initial_out_time}")
    generate_table_bottom(2)
    puts ' '
    print 'Enter your choice : '
    choice = gets.chomp.to_i

    case choice
    when 1
      print 'Enter new daily salary: '
      @initial_daily_salary = gets.chomp.to_f
    when 2
      print 'Enter new max regular work hours: '
      @max_regular_work_hours = gets.chomp.to_i
    when 3
      print 'Enter new number of workdays: '
      @workdays = gets.chomp.to_i
    when 4
      print 'Enter new initial day type: '
      @initial_day_type = gets.chomp
    when 5
      print 'Enter new initial in time: '
      @initial_in_time = gets.chomp
    when 6
      print 'Enter new initial out time: '
      @initial_out_time = gets.chomp
    else
      puts 'Invalid Input.'
    end
  end

  def parse_military_time(time_str)
    # Use Time.new to parse military time string without colon
    Time.strptime(time_str.to_s, '%H%M')
  end

  def compute_hours_difference_ns(start_time, end_time)
    # Parse the input strings into Time objects
    start_time = parse_military_time(start_time)
    end_time = parse_military_time(end_time)

    # Calculate the time difference in seconds
    difference_in_seconds = end_time - start_time

    # If the end time is before the start time, add 24 hours to consider the next day
    difference_in_seconds += 24 * 60 * 60 if difference_in_seconds.negative?

    # Convert the time difference to hours
    difference_in_hours = difference_in_seconds / 3600

    difference_in_hours.to_i
  end

  def compute_hours_difference(start_time, end_time)
    # Parse the input strings into Time objects
    start_time = parse_military_time(start_time)
    end_time = parse_military_time(end_time)

    # Calculate the time difference in seconds and convert to hours
    difference_in_hours = [(end_time - start_time) / 3600, 0].max

    difference_in_hours.to_i # Convert to integer
  end

  def within_time_range?(target_hour_str, start_hour_str, end_hour_str)
    target_hour = target_hour_str.to_i
    start_hour = start_hour_str.to_i
    end_hour = end_hour_str.to_i

    if start_hour <= end_hour
      # Range is within a single day
      target_hour.between?(start_hour, end_hour)
    else
      # Range spans across midnight (e.g., 1800 to 0300)
      target_hour >= start_hour || target_hour <= end_hour
    end
  end

  def calculate_nth_hour(start_time, n)
    # Convert start_time to DateTime object
    start_datetime = DateTime.strptime(start_time, '%H%M')

    # Calculate nth hour
    nth_hour_datetime = start_datetime + Rational(n, 24)

    # Format nth_hour_datetime as HHMM string
    nth_hour_datetime.strftime('%H%M')
  end

  def simulate_week
    # Assumptions (from specs):
    # - Employees are not late
    # - Employees work for at least 8 hours
    # - Employees may be absent

    # General formula for computing daily salary (I made this myself so it might be wrong):
    # IF normal day and employee did not work (in time = out time)
    #   then salary = 0
    # ELSE
    #   then salary = (daily rate * day type)
    #   IF NOT OT (in time to out time <= max regular work hours + 1 rest hour)
    #     + (Hours on night shift * daily rate / max regular work hours * night shift duty (1.10))
    #   ELSE
    #     + (Hours OT * daily rate / max regular work hours * day shift OT rate corresponding to day type)
    #     + (Night shift Hours OT * daily rate / max regular work hours * night shift OT rate corresponding to day type)

    day_ctr = 1

    salary_array.length.times do
      # Initialize table
      daily_rate = initial_daily_salary
      in_time = initial_in_time
      out_time = initial_out_time
      day_type = initial_day_type
      salary = 0

      loop do
        puts '---'
        generate_table_top(2, false)
        generate_header("Simulate Week (Day #{day_ctr})", 2)
        generate_header("Accumulated Salary: #{@salary_array}", 2)
        generate_table_middle(2)
        generate_row('Daily Rate', "#{daily_rate}")
        generate_row('[1] IN Time', "#{in_time}")
        generate_row('[2] OUT Time', "#{out_time}")
        generate_row('[3] Day Type', "#{day_type}")
        generate_table_bottom(2)
        puts ' '
        print 'Enter your choice (to finish editing day, enter 0): '
        choice = gets.chomp.to_i

        case choice
        when 1
          print 'Enter in time: '
          in_time = gets.chomp
        when 2
          print 'Enter out time: '
          out_time = gets.chomp
        when 3
          print 'Enter day type: '
          day_type = gets.chomp
        when 0
          if in_time == out_time && day_type == 'Normal Day'
            salary = 0

            generate_table_top(2, false)
            generate_header("Output Table (Day #{day_ctr})", 2)
            generate_table_middle(2)
            generate_row('Daily Rate', "#{daily_rate}")
            generate_row('IN Time', "#{in_time}")
            generate_row('OUT Time', "#{out_time}")
            generate_row('Day Type', "#{day_type}")
            generate_row('Hours Overtime (Night Shift Overtime)', '0 (0)')
            generate_row('Salary for the day', "#{salary.round(2)}")
            generate_table_bottom(2)
          else
            # Computing (daily rate * day type)
            case day_type
            when 'Normal Day'
              salary += daily_rate * 1
            when 'Rest Day'
              salary += daily_rate * 1.30
            when 'SNWH'
              salary += daily_rate * 1.30
            when 'SNWH, Rest Day'
              salary += daily_rate * 1.50
            when 'RH'
              salary += daily_rate * 2.00
            when 'RH, Rest Day'
              salary += daily_rate * 2.60
            end

            # Check whether employee did NOT DO overtime (exceeding 8 hours + 1 break hour)
            if compute_hours_difference(in_time, out_time) <= max_regular_work_hours + 1
              # Computing (Hours on night shift * daily rate / max regular work hours * night shift duty (1.10))
              if within_time_range?('2200', in_time, out_time)
                night_shift_hours = compute_hours_difference_ns(2200, out_time)
                salary += night_shift_hours * daily_rate / max_regular_work_hours * 1.10

                generate_table_top(2, false)
                generate_header("Output Table (Day #{day_ctr})", 2)
                generate_table_middle(2)
                generate_row('Daily Rate', "#{daily_rate}")
                generate_row('IN Time', "#{in_time}")
                generate_row('OUT Time', "#{out_time}")
                generate_row('Day Type', "#{day_type}")
                generate_row('Hours on Night Shift', "#{night_shift_hours}")
                generate_row('Salary for the day', "#{salary.round(2)}")
                generate_table_bottom(2)
              else
                # Day Shift without Overtime
                generate_table_top(2, false)
                generate_header("Output Table (Day #{day_ctr})", 2)
                generate_table_middle(2)
                generate_row('Daily Rate', "#{daily_rate}")
                generate_row('IN Time', "#{in_time}")
                generate_row('OUT Time', "#{out_time}")
                generate_row('Day Type', "#{day_type}")
                generate_row('Hours Overtime (Night Shift Overtime)', '0 (0)')
                generate_row('Salary for the day', "#{salary.round(2)}")
                generate_table_bottom(2)
              end
            else
              # Computing (Hours OT * daily rate / max regular work hours * day shift OT rate corresponding to day type)
              hours_OT = [compute_hours_difference(calculate_nth_hour(in_time, @max_regular_work_hours + 1), 2200),
                          compute_hours_difference(calculate_nth_hour(in_time, @max_regular_work_hours + 1),
                                                   out_time)].min

              case day_type
              when 'Normal Day'
                salary += hours_OT * daily_rate / max_regular_work_hours * 1.25
              when 'Rest Day'
                salary += hours_OT * daily_rate / max_regular_work_hours * 1.69
              when 'SNWH'
                salary += hours_OT * daily_rate / max_regular_work_hours * 1.69
              when 'SNWH, Rest Day'
                salary += hours_OT * daily_rate / max_regular_work_hours * 1.95
              when 'RH'
                salary += hours_OT * daily_rate / max_regular_work_hours * 2.60
              when 'RH, Rest Day'
                salary += hours_OT * daily_rate / max_regular_work_hours * 3.38
              end

              # Computing (Night shift Hours OT * daily rate / max regular work hours * night shift OT rate corresponding to day type)
              hours_OT_NS = compute_hours_difference(2200, out_time)

              case day_type
              when 'Normal Day'
                salary += hours_OT_NS * daily_rate / max_regular_work_hours * 1.375
              when 'Rest Day'
                salary += hours_OT_NS * daily_rate / max_regular_work_hours * 1.859
              when 'SNWH'
                salary += hours_OT_NS * daily_rate / max_regular_work_hours * 1.859
              when 'SNWH, Rest Day'
                salary += hours_OT_NS * daily_rate / max_regular_work_hours * 2.145
              when 'RH'
                salary += hours_OT_NS * daily_rate / max_regular_work_hours * 2.860
              when 'RH, Rest Day'
                salary += hours_OT_NS * daily_rate / max_regular_work_hours * 3.718
              end

              generate_table_top(2, false)
              generate_header("Output Table (Day #{day_ctr})", 2)
              generate_table_middle(2)
              generate_row('Daily Rate', "#{daily_rate}")
              generate_row('IN Time', "#{in_time}")
              generate_row('OUT Time', "#{out_time}")
              generate_row('Day Type', "#{day_type}")
              generate_row('Hours Overtime (Night Shift Overtime)', "#{hours_OT} (#{hours_OT_NS})")
              generate_row('Salary for the day', "#{salary.round(2)}")
              generate_table_bottom(2)
            end
          end

          @salary_array[day_ctr - 1] = salary.round(2) # pushes sthe salary for the day to the array

          day_ctr += 1 # moves on to the next day

          break # ends the loop and begins the next day
        end
      end
    end
  end

  def generate_payroll
    generate_table_top(2, false)
    generate_header('Generate Payroll', 2)
    generate_table_middle(2)
    for i in 1..7
      generate_row("Day #{i}", "#{@salary_array[i - 1]}")
    end

    if @salary_array.all? { |element| element.nil? }
      generate_row('Total Salary for the Week', '0')
    else
      generate_row('Total Salary for the Week', "#{@salary_array.sum}")
    end

    generate_table_bottom(2)
  end
end

# Main program
payroll_system = MP_3_Ruby.new

loop do
  puts('---')
  generate_table_top(1)
  generate_row('Payroll System Menu')
  generate_table_middle(1)
  generate_row('[1] Modify Default Configurations')
  generate_row('[2] Simulate Week')
  generate_row('[3] Generate Payroll')
  generate_row('[4] Exit')
  generate_table_bottom(1)
  puts ' '
  print 'Enter your choice : '
  choice = gets.chomp.to_i

  case choice
  when 1
    payroll_system.modify_configurations
  when 2
    payroll_system.simulate_week
  when 3
    payroll_system.generate_payroll
  when 4
    puts 'Exiting program...'
    break
  else
    puts 'Invalid Input. Please try again'
  end
end